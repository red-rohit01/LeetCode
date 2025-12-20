class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int c=0;
        for(int i=0;i<strs[0].size();i++)
        {
            for(int k=0;k<strs.size()-1;k++)
            {
                if(strs[k][i]>strs[k+1][i])
                {
                    c++;
                    break;
                }
            }
        }
        return c; 
    }
};