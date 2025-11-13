class Solution {
public:
    int maxOperations(string s) {
        int n=s.size();
        int ans=0;
        int one=0;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='1') one++;

            else if(i>0 && s[i-1]=='1') ans+=one;
        }
        return ans;
    }
};