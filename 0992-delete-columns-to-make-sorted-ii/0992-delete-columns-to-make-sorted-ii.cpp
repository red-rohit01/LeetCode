class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int len=strs[0].size();

        int del=0;
        vector<bool>cuts(n-1);      // cuts[j] is true ==> we don't need to check any new strs[i][j]<=strs[i][j+1]
        for(int j=0;j<len;++j)
        {
            int i=0;
            for(;i<n-1;++i)
            {
                if(cuts[i]==false && strs[i][j]>strs[i+1][j])
                {
                    del++;
                    break;
                }
            }

            if(i<n-1) continue;

            for(int i=0;i<n-1;++i) 
            {
                cuts[i]= cuts[i] || (strs[i][j]<strs[i+1][j]);
            }
        }
        return del;
    }
};