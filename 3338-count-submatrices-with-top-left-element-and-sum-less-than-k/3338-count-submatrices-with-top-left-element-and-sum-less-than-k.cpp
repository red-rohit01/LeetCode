class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                int prev1=0,prev2=0;
                int prev3=0;
                if(i>0) prev1=grid[i-1][j];
                if(j>0) prev2=grid[i][j-1];
                if(i>0 && j>0) prev3=grid[i-1][j-1];
                grid[i][j]=prev1+prev2+grid[i][j]-prev3;
            }
        }
        int ans=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]<=k) ans++;
            }
        }
        return ans;
    }
};