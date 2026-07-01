class Solution {
public:
    int dr[5]={1,0,-1,0,1};
    bool valid(int mid,vector<vector<int>>&dist)
    {
        int n=dist.size();
        vector<vector<int>>vis(n,vector<int>(n));
        if(dist[0][0] < mid) return false;

        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0]=1;
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            int row=temp.first;
            int col=temp.second;
            if(row==n-1 && col==n-1) return true;

            for(int k=0;k<4;++k)
            {
                int nrow=row+dr[k];
                int ncol=col+dr[k+1];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && dist[nrow][ncol]>=mid && vis[nrow][ncol]==0)
                {
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return 0;

        int ans=0,l=0,h=n-1;
        vector<vector<int>>dist(n,vector<int>(n,-1));

        queue<pair<int,int>>q;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]==1)
                {
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            int row=temp.first;
            int col=temp.second;
            for(int k=0;k<4;++k)
            {
                int nrow=row+dr[k];
                int ncol=col+dr[k+1];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && dist[nrow][ncol]==-1)
                {
                    dist[nrow][ncol]=1+dist[row][col];
                    q.push({nrow,ncol});
                }
            }
        }
        while(l<=h)
        {
            int mid=l+(h-l)/2;

            if(valid(mid,dist))
            {
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;

            //cout<<ans<<"\n";
        }
        return ans;
    }
};