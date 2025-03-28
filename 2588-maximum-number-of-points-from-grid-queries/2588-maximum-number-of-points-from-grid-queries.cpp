class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m=grid.size();
        int n=grid[0].size();
        int k=queries.size();
        vector<pair<int,int>>rk(k);
        for(int i=0;i<k;++i)
        {
            rk[i].first=queries[i];
            rk[i].second=i;
        }

        int dr[5]={1,0,-1,0,1};
        sort(rk.begin(),rk.end());          
        vector<int>ans(k);
        int cnt=0;
        priority_queue<vector<int>>pq;      // We'll treat it as min priority queue by storing negative values.
        pq.push({-grid[0][0],0,0});
        grid[0][0]=0;
        for(auto &x:rk)
        {

            while(pq.size()>0 && abs(pq.top()[0])< x.first)
            {
                vector<int>temp=pq.top();
                pq.pop();

                cnt++;
                for(int r=0;r<4;++r)
                {
                    int nx=temp[1]+dr[r];
                    int ny=temp[2]+dr[r+1];

                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]>0)
                    {
                        pq.push({-grid[nx][ny],nx,ny});
                        grid[nx][ny]=0;
                    }
                }
            }
            ans[x.second]=cnt;
        }
        return ans;
    }
};

