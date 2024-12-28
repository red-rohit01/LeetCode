class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int n=s.size();
        vector<int>dp(n+1,n);
        dp[0]=0;
        for(int i=1;i<=n;++i)
        {
            vector<int>freq(26);

            for(int j=i;j>0;--j)
            {
                int ind=(s[j-1]-'a');
                freq[ind]++;
                int mx=0;
                int mn=n;
                for(int k=0;k<26;++k)
                {
                    if(freq[k]!=0)
                    {
                        mx=max(mx,freq[k]);
                        mn=min(mn,freq[k]);
                    }
                }
                if(mx==mn) dp[i]=min(dp[i],1+dp[j-1]);
            }
        }
        return dp[n];
    }
};