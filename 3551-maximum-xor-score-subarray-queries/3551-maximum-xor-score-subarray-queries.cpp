class Solution {
public:
    // Since, Similar to LCS (Least Common Subarray)
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int m=queries.size();
        vector<vector<int>>dp(n,vector<int>(n));
        for(int i=0;i<n;++i) dp[i][i]=nums[i];

        for(int len=2;len<=n;++len)
        {
            for(int st=0;(st+len-1)<n;++st)
            {
                int en=st+len-1;            // -1 since It's 0 based indexing
                dp[st][en]=(dp[st][en-1]^dp[st+1][en]);
            }
        }

        for(int len=2;len<=n;++len)
        {
            for(int st=0;(st+len-1)<n;++st)
            {
                int en=st+len-1;            // -1 since It's 0 based indexing
                dp[st][en]=max({dp[st][en], dp[st][en-1], dp[st+1][en]}); //To build the max from ind 'i' to 'j', we are taking help
            }                    // of only two values dp[st][en-1] and dp[st+1][en]. That's why taking maxm of these three values
        }

        vector<int>ans(m);
        for(int i=0;i<m;++i)
        {
            int u=queries[i][0];
            int v=queries[i][1];

            ans[i]=(dp[u][v]);
        }
        return ans;
    }
};