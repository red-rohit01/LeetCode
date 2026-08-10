class Solution {
public:
    // detailed explanation: https://leetcode.com/problems/stone-game-iv/solutions/8451674/beats-100-dynamic-programming-all-langua-jueu/?envType=daily-question&envId=2026-08-10
    bool winnerSquareGame(int n) {
        vector<bool>dp(n+1);

        for(int i=0;i<=n;++i)
        {
            // if 'i' is a losing position, every valid square move from i creates a winning position
            if(!dp[i])
            {
                for(int j=1;i+j*j<=n;++j) dp[i+j*j]=true;

                // once 'n' becomes reachable from a losing position, the first player can force a win

                if(dp[n]) return true;
            }
        }
        return false;
    }
};