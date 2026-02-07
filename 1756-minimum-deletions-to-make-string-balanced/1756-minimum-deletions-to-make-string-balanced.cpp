class Solution {
public:
    // One of the very good solution is using the two variable method ->editorial (Space Complexity-> O(1))
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int>dp(n+1);
        int b_count=0;

        // dp[i]: The number of deletions required to balance the substring s[0, i)
        for (int i=0;i<n;++i) 
        {
            if (s[i]=='b') 
            {
                dp[i+1]=dp[i];
                b_count++;
            } 
            else 
            {
                // Two cases: remove 'a' or keep 'a'      dp[i]+1 --> 'a' removed   b_count-> all 'b' before that removed
                dp[i+1]=min(dp[i]+1, b_count);
            }
        }
        return dp[n];
    }
};