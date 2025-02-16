class Solution {
public:
    // int dx[4]={1,-1,0,0};
    // int dy[4]={0,0,1,-1};
    // void dfs(int row,int col,int temp,int cnt,vector<vector<bool>>vis,vector<vector<int>>&grid,int &ans,int &m,int &n)
    // {
    //     vis[row][col]=1;
    //     if(grid[row][col]==2)
    //     {
    //         //cout<<temp<<" "<<cnt<<" "<<ans<<"\n";
    //         if(temp==cnt)
    //         {
    //             ans++;
    //             //cout<<temp<<" "<<cnt<<" "<<ans<<"\n";
    //         }
    //         return;
    //     }

    //     for(int i=0;i<4;++i)
    //     {
    //         int newr=row+dx[i];
    //         int newc=col+dy[i];
    //         if(newr>=0 && newr<m && newc>=0 && newc<n && grid[newr][newc]!=-1 && vis[newr][newc]==0)
    //         {
    //             dfs(newr,newc,temp+1,cnt,vis,grid,ans,m,n);
    //         }
    //     }
    // }

    vector<int>dr={-1,0,1,0,-1};
    bool isvalid(int nr,int nc,int &m,int &n,vector<vector<int>>&grid, long long mask)
    {
        if(nr<0 || nr>=m || nc<0 || nc>=n || grid[nr][nc]==-1) return false;

        if((mask&(1LL<<(nr*n+nc)))!=0) return false;   // If it's already visited then return false

        return true;
    }
    int helper(vector<vector<int>>&grid,int row, int col, long long mask, int &m,int &n)
    {
        if(grid[row][col]==2) return (mask==((1LL<<(n*m))-1));

        int ans=0;
        for(int k=0;k<4;++k)
        {
            int newr=row+dr[k];     
            int newc=col+dr[k+1];

            if(isvalid(newr,newc,m,n,grid,mask))
            {
                mask^=(1LL<<(newr*n +newc));   // setting up the i'th bit
                ans+=helper(grid,newr,newc,mask,m,n);
                mask^=(1LL<<(newr*n +newc));   // unsetting it up
            }
        }
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        // int cnt=0;
        // int str=0,stc=0;
        // for(int i=0;i<m;++i)
        // {
        //     for(int j=0;j<n;++j)
        //     {
        //         if(grid[i][j]==1)
        //         {
        //             str=i;
        //             stc=j;
        //         }
        //         if(grid[i][j]== -1) cnt++;
        //     }
        // }
        // cnt=(m*n)-cnt;

        // vector<vector<bool>>vis(m,vector<bool>(n));
        // vis[str][stc]=1;
        // int ans=0;
        // dfs(str,stc,1,cnt,vis,grid,ans,m,n);
        // return ans;

        long long mask=0;
        int st_i=0,st_j=0;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]==1)
                {
                    st_i=i;
                    st_j=j;
                    mask^=(1LL<<(i*n+j));
                }
                else if(grid[i][j]==-1)
                {
                    mask^=(1LL<<(i*n+j));
                }
            }
        }

        return helper(grid,st_i,st_j,mask,m,n);
    }
};