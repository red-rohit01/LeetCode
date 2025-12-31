class Solution {
public:
    int dr[5]={1,0,-1,0,1};
    bool check(vector<vector<int>>&cells,int row,int col,int mid)
    {
        vector<vector<int>>grid(row,vector<int>(col));
        queue<pair<int,int>>q;
        for(int i=0;i<mid;++i) 
        {
            int u=cells[i][0];
            int v=cells[i][1];
            grid[u-1][v-1]=1;
        }
        for(int j=0;j<col;++j)
        {
            if(grid[0][j]==0)
            {
                q.push({0,j});
                grid[0][j]=-1;
            }
        }
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            int r=temp.first;
            int c=temp.second;
            if(r== row-1) return true;

            for(int k=0;k<4;++k)
            {
                int nr=r+dr[k];
                int nc=c+dr[k+1];

                if(nr>=0 && nr<row && nc>=0 && nc<col && grid[nr][nc]==0) 
                {
                    grid[nr][nc]=-1;
                    q.push({nr,nc});
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l=1;
        int h=row*col;
        int ans=1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(check(cells,row,col,mid))
            {
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        return ans;
    }
};