class Solution {
public:
    // https://leetcode.com/problems/distinct-subsequences-ii/solutions/8506562/trust-me-its-not-hard-optimized-time-spa-yoa5/
    int distinctSubseqII(string s) {
        int n = s.size();
        int MOD = 1e9 + 7;

        vector<int> countEndWith(26);

        int sum = 0;

        for(int i = 0; i < n; i++)
        {
            int idx = s[i] - 'a';

            // Create new subsequences and remove duplicates
            int cur = (1 + sum - countEndWith[idx] + MOD) % MOD;

            sum = (sum + cur) % MOD;

            // Update subsequences ending with this character
            countEndWith[idx] = (countEndWith[idx] + cur) % MOD;
        }

        return sum;
    }
};