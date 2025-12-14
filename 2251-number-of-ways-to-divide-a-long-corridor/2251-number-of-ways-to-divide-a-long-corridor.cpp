class Solution {
public:
    const long long mod=1e9+7;
    int numberOfWays(string corridor) {
        int n=corridor.size();
        int cnt=0;
        for(int i=0;i<n;++i)
        {
            if(corridor[i]=='S') cnt++;
        }
        if(cnt%2 || cnt==0) return 0;

        int ans=1;
        int curr=0;
        for(int i=0;i<n;++i)
        {
            if(corridor[i]=='S') curr++;

            if(curr==2)
            {
                curr=0;
                int j=i+1;
                while(j<n && corridor[j]=='P') j++;
                
                int temp=j-i;
                i=j-1;
                if(j==n) continue;
                ans=(ans%mod * temp%mod)%mod;
            }
        }
        return ans;
    }
};