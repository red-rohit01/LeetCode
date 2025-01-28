class Solution {
public:
    int dr[5]={1,0,-1,0,1};
    void dfs(vector<vector<int>>& grid,int i,int j,int m,int n,int& value,vector<vector<int>>&vis)
    {
        vis[i][j]=1;
        for(int k=0;k<4;++k)
        {
            int newi=i+dr[k];
            int newj=j+dr[k+1];
            if(newi>=0 && newi<m && newj>=0 && newj<n && grid[newi][newj]>0 && vis[newi][newj]==0)
            {
                value+=grid[newi][newj];
                dfs(grid,newi,newj,m,n,value,vis);
            }
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>ans(m,vector<int>(n));
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]==0) continue;

                vector<vector<int>>vis(m,vector<int>(n));
                int value=grid[i][j];
                dfs(grid,i,j,m,n,value,vis);
                ans[i][j]=value;
            }
        }
        int res=0;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                res=max(res,ans[i][j]);
            }
        }
        return res;
    }
};