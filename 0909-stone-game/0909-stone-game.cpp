class Solution {
public:
    // Approach2:
    // It's always possible for Alice to win.
    // If Alice takes the first pile initially, she can always take the third pile. If she takes the fourth pile initially, she can always take the second pile. At least one of first + third, second + fourth is larger, so she can always win.

    // Now divide the piles based on their original indices:
    // Even indexed piles: 0, 2, 4, ...
    // Odd indexed piles: 1, 3, 5, ...
    // Because the number of piles is even, Alice can force herself to take either all the even-indexed piles or all the odd-indexed piles.

    // She can decide which group she wants based on her first move.
    // Since the total number of stones is odd: sum(even indexed piles) != sum(odd indexed piles)
    // Therefore, one of these two groups must have a larger sum.

    bool stoneGame(vector<int>& piles) {
        int n=piles.size();

        // dp[i][j] == represents the maximum score difference the current player can achieve from piles [i....j]
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));

        for(int i=0;i<n;++i) dp[i][i]=piles[i];

        for(int len=2;len<=n;++len)  // we need to process intervals by Length because dp[i][j] needs both dp[i+1][j] and dp[i][j-1]
        {
            for(int i=0; i+len-1<n ; ++i)
            {
                int j=i+len-1;

                int takeLeft=piles[i]-dp[i+1][j];    // we subtracted the opponent advantage
                int takeRight=piles[j]-dp[i][j-1];

                dp[i][j]=max(takeLeft, takeRight);
            }
        } 

        return dp[0][n-1]>0;
    }
};