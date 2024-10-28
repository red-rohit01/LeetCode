class Solution {
public:
    int cnt_helper(vector<vector<int>>grid)
    {                           // 1 1 1 1 1             1 1 1 1 1
        int m=grid.size();      // 0 1 1 1 0     ---->   0 2 2 2 0
        int n=grid[0].size();   // 0 1 1 1 0             0 1 3 1 0
        
        int ans=0;
        for(int i=1;i<m;++i)
        {
            for(int j=1;j<(n-1);++j)
            {
                if(grid[i][j] && grid[i-1][j])
                {
                    int curr=min(grid[i-1][j-1], grid[i-1][j+1])+1;
                    grid[i][j]=curr;
                    ans+=(curr-1);          // The contribution of curr height in 'ans' will be 1 less
                }
            }
        }
        return ans;
    }
    int countPyramids(vector<vector<int>>& grid) {
        int ans=cnt_helper(grid);        // Initially we'll cnt the number of inverse pyramids
        reverse(grid.begin(),grid.end());      // Now the Matrix is upside down
        ans+=cnt_helper(grid);          // Number of normal pyramids
        return ans;
    }
};