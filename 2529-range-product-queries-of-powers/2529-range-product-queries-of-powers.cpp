class Solution {
public:
    // It can be solved with normal multiplication too for each of the queries w/o using 'modinv' as for the given value of 'n' maximum
    // no. of setbits can be 31 only. so, For each of the query, we need to traverse atmost 31 only. 
    const long long mod=1000000007;
    long long modexpo(long long a, long long b) {
        if (b == 0)
            return 1;
        long long p = modexpo(a, b / 2) % mod;
        p = (p * p) % mod;
        return (b % 2 == 0) ? p : (a * p) % mod;
    }
    long long modinv(long long a) {
        long long g = __gcd(a, mod);
        if (g != 1)
            return -1;
        else {
            return modexpo(a, mod- 2);
        }
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int len=__builtin_popcount(n);
        vector<int>power(len);
        int temp=n;
        int i=0,k=0;
        while(temp>0)
        {
            if(temp&1)
            {
                power[k]=pow(2,i);
                k++;
            }
            temp/=2;
            i++;
        }
        vector<long long>dp(len);
        dp[0]=1LL*power[0];
        for(int i=1;i<len;++i)
        {
            dp[i]=(dp[i-1]%mod * power[i]%mod) %mod;
        }
        int l=queries.size();
        vector<int>ans(l);
        
        for(int i=0;i<l;++i)
        {
            int a=queries[i][0];
            int b=queries[i][1];
            int res=dp[b];
            if(a>0) res=(res%mod * modinv(dp[a-1])%mod)%mod;
            ans[i]=res;
        }
        return ans;
    }
};