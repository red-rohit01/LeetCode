class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size(), n = strs[0].length(), res = n - 1, k;
        vector<int>dp(n, 1);
        for (int j = 0; j < n; ++j) 
        {
            for (int i = 0; i < j; ++i) 
            {
                for (k = 0; k < m; ++k) 
                {
                    if (strs[k][i] > strs[k][j]) break;
                }
                if (k == m && dp[i] + 1 > dp[j])
                    dp[j] = dp[i] + 1;
            }
            res = min(res, n - dp[j]);
        }
        return res;
    }
};