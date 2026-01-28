class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();

        int maxVal=0;
        for (auto& row : grid)
            for (int v : row)
                maxVal=max(maxVal, v);

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));    // dp[i][j]=min cost to reach (n-1,m-1) from (i,j)
        vector<int> temp(maxVal+1, INT_MAX);       // temp[v] == min cost starting from any cell with value 'v'
        vector<int> best(maxVal+1);

        temp[grid[n-1][m-1]]=0;
        dp[n-1][m-1]=0;

        for (int i = n - 1; i >= 0; i--) 
        {
            for (int j = m - 1; j >= 0; j--) 
            {
                if (i == n - 1 && j == m - 1) continue;

                int down = (i + 1 < n && dp[i + 1][j] != INT_MAX)
                    ? dp[i + 1][j] + grid[i + 1][j]
                    : INT_MAX;

                int right = (j + 1 < m && dp[i][j + 1] != INT_MAX)
                    ? dp[i][j + 1] + grid[i][j + 1]
                    : INT_MAX;

                dp[i][j] = min(down, right);

                if (dp[i][j] != INT_MAX) temp[grid[i][j]]=min(temp[grid[i][j]], dp[i][j]);
            }
        }

        for (int x = 0; x < k; x++) 
        {
            best[0]=temp[0];
            for (int v = 1; v <= maxVal; v++)
                best[v] = min(best[v - 1], temp[v]);

            for(int i = n - 1; i >= 0; i--) 
            {
                for(int j = m - 1; j >= 0; j--) 
                {
                    if(i ==n - 1 && j == m - 1) continue;

                    int down = (i + 1 < n && dp[i + 1][j] != INT_MAX)
                        ? dp[i + 1][j] + grid[i + 1][j]
                        : INT_MAX;
                    int right = (j + 1 < m && dp[i][j + 1] != INT_MAX)
                        ? dp[i][j + 1] + grid[i][j + 1]
                        : INT_MAX;

                    int walkCost = min(down, right);
                    int teleportCost = best[grid[i][j]];

                    dp[i][j]=min(walkCost, teleportCost);

                    if(dp[i][j]!=INT_MAX) temp[grid[i][j]]=min(temp[grid[i][j]], dp[i][j]);
                }
            }
        }
        return dp[0][0];
    }
};