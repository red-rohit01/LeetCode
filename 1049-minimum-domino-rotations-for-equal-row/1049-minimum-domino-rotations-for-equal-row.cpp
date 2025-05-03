class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int len=tops.size();
        int ans=len;

        vector<int>upper(7);
        vector<int>lower(7);
        vector<int>same(7);
        for(int i=0;i<len;++i)
        {
            if(tops[i]!=bottoms[i])
            {
                upper[tops[i]]++;
                lower[bottoms[i]]++;
            }
            else same[tops[i]]++;            
        }

        for(int i=1;i<=6;++i) 
        {
            if((upper[i]+lower[i]+same[i])>=len)
            {
                int curr=upper[i];
                curr=min(curr,lower[i]);
                ans=min(ans,curr);
            }
        }
        if(ans==len) return -1;
        return ans;
    }
};