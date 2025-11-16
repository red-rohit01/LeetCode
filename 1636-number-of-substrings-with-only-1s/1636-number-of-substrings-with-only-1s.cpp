class Solution {
public:
    const int mod=1e9+7;
    int numSub(string s) {
        int n=s.size();
        int ans=0;
        int prev=0;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='1')
            {
                prev++;
                ans=(ans%mod + prev%mod)%mod;
            }
            else prev=0;
        }
        return ans;
    }
};