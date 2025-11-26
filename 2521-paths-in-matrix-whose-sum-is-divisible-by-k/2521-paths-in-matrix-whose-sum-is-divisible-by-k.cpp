class Solution {
    const int mod=1000000007;
    vector<vector<vector<int>>> dp;
    
    int helper (int i, int j, int modulus_val,int m,int n,const vector<vector<int>>& grid, const int K) {
        
        if (i >= m || j >= n) return 0;
        if (i == m-1 && j == n-1) return (grid[i][j] % K == modulus_val);
        
        int &ans = dp[i][j][modulus_val];
        if (ans != -1) return ans;
        
        int remainder = (modulus_val - (grid[i][j] % K) + K) % K;
        ans = (helper (i+1, j, remainder,m,n, grid, K) + helper(i, j+1, remainder,m,n, grid, K)) % mod;
        return ans;
    }
    
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        dp.clear();
        int m = grid.size();
        int n = grid[0].size();
        
        dp.resize (m, vector<vector<int>>(n, vector<int>(k, -1)));
        return helper(0, 0, 0,m,n, grid, k);
    }
};