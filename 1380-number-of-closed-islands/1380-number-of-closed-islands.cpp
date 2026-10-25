class Solution {
public:
    bool dfs(vector<vector<int>>& g, int i, int j){
        if(i<0 || j<0 || i>=g.size() || j>=g[0].size()) return false;
        
        if(g[i][j]==1) return true;
        
        g[i][j] = 1;
        /*I CANNOT USE `return dfs(g, i+1, j) && dfs(g, i, j+1) && dfs(g, i-1, j) && dfs(g, i, j-1);`
        BECAUSE IF ANY OF THE FIRST DFS() RETURNS FALSE, FOLLOWING ONES WILL NOT EXECUTE!!! THEN WE DON'T
        HAVE THE CHANCE TO MARK THOSE 0s TO 1s!!!
        */
        bool d1=dfs(g, i+1, j);
        bool d2=dfs(g, i, j+1);
        bool d3=dfs(g, i-1, j);
        bool d4=dfs(g, i, j-1);
        return d1 && d2 && d3 && d4;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int res=0;
        int m=grid.size();
        int n=grid[0].size();
        for (int i = 0;i<m;++i)
        {
            for (int j=0;j<n;++j)
            {
                if (grid[i][j]==0) res+=dfs(grid,i,j)?1:0;
            }
        }
        return res;
    }
};