class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int l=grid[0][0],h=n*n;

        int ans=h;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            vector<vector<int>>vis(n,vector<int>(n,-1));
            vis[0][0]=1;
            vector<int>dr={-1,0,1,0,-1};
            queue<pair<int,int>>q;
            q.push({0,0});
            bool flag=false;
            while(!q.empty())
            {
                auto temp=q.front();
                q.pop();

                if(temp.first==n-1 && temp.second==n-1)
                {
                    flag=true;
                    break;
                }
                for(int k=0;k<4;++k)
                {
                    int ni=temp.first+dr[k];
                    int nj=temp.second+dr[k+1];

                    if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj]<=mid && vis[ni][nj]==-1)
                    {
                        q.push({ni,nj});
                        vis[ni][nj]=1;
                    }
                }
            }
            if(flag==true)
            {
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};