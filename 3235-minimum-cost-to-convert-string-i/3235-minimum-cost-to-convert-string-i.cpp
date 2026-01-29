class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n=original.size();
        vector<vector<long long>>dp(26,vector<long long>(26,INT_MAX));

        for(int i=0;i<n;++i)
        {
            int ind1=original[i]-'a';
            int ind2=changed[i]-'a';
            dp[ind1][ind2]=min(dp[ind1][ind2],1LL*cost[i]);
        }

        for(int via=0;via<26;++via)
        {
            for(int i=0;i<26;++i)
            {
                for(int j=0;j<26;++j)
                {
                    if(dp[i][via]!=INT_MAX && dp[via][j]!=INT_MAX) dp[i][j]=min(dp[i][j],dp[i][via]+dp[via][j]);
                }
            }
        }

        long long ans=0;
        int len=source.size();
        for(int i=0;i<len;++i)
        {
            if(source[i]!=target[i])
            {
                int ind1=source[i]-'a';
                int ind2=target[i]-'a';
                if(dp[ind1][ind2]==INT_MAX) return -1;

                ans+=dp[ind1][ind2];
            }
        }
        return ans;
    }
};