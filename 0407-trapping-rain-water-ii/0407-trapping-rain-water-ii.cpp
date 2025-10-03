class Solution {
public:
    // Feels like the idea is that for each cell take the maximum from all four directions and then take the minm of all these values as
    // the boundary corresponding to this particular cell.
    // If we are thinking of converting the classic trapping rain water to this,
    // then it might not work as expected. Lets say, for each position, you compute the
    // horizontal blocking height and the vertical blocking height. Now that you know the
    // blocking heights for all 4 dirs, you might think the volume computation from min of these
    // blocking heights will give the answer, but it won't give optimal answer.
    
    // Reason being, that we are not considering the case when any of the connecting horizontal or
    // vertical blocks might have a way to drain the water.
    
    // 4 4 4 4
    // 4 3 3 4
    // 4 4 3 4,
    // Here as we can see even though horizontal and vertical blocking height logic seems to give ans = 1 (at (1, 1) block), in reality
    // it is 0. The block at (1, 2) will spill the water via (2, 2) and won't be able to hold any water, so the block at
    // (1, 1) won't be able to hold any water as well no matter what.
    
    // The idea is to use min_height from any of the boundary 
    // What if we are able to find a way to approach a block via its min height blocking cell and then just check if the height of min block
    // cell is greater than curr. If it is greater, then curr cell can hold water, this is because we were able to reach the current cell via
    // the min height blocking cell and that means remaining blocking cells are all greater in height than this path cell. So if this path cell
    // is greater than current, then all other blocking cells are greater as well.
    
    // Now to actually do this in practice, we make use of min heap. We add the initial border cells to heap. Then slowly start reaching the inner
    // cells via the shortest height boundary cells, while keeping track of tallest cell boundary in the path.
    // Each time we reach an inner cell, there are 2 possibilities:
    // 1. Inner cell is greater, then we add this to heap as well. This can act as a blocking height for more inner cells.
    // 2. Inner cell is smaller, then we know that this inner call can hold water = path_cell - inner_cell. Add this to heap as well
    
    // While adding new elements to heap, make sure to add the max height of that path, since that is the actual boundary in that path.
    
    // TC: O(MNlog(MN))
    // SC: O(MN)
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size();
        int m=heightMap[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m));

        int ans=0;
        vector<int>dr={-1,0,1,0,-1};
        
        // <height, row, col>
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>>pq; // min priority queue

        // Adding all the boundary cells from Top and Bottom
        for(int j=0;j<m;++j)
        {
            pq.push({heightMap[0][j],0,j});
            pq.push({heightMap[n-1][j],n-1,j});
            vis[0][j]=1;
            vis[n-1][j]=1;
        }

        // Adding all the boundary cells from left and right
        for(int i=0;i<n;++i)
        {
            pq.push({heightMap[i][0],i,0});
            pq.push({heightMap[i][m-1],i,m-1});
            vis[i][0]=1;
            vis[i][m-1]=1;
        }

        while(!pq.empty())
        {
            auto temp=pq.top();
            pq.pop();

            int height=temp[0];
            int r=temp[1];
            int c=temp[2];

            for(int k=0;k<4;++k)
            {
                int nr=r+dr[k];
                int nc=c+dr[k+1];

                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0)
                {
                    vis[nr][nc]=1;
                    if(heightMap[nr][nc]<height) ans+=(height-heightMap[nr][nc]);

                    pq.push({max(height,heightMap[nr][nc]), nr,nc});
                }
            }
        }
        return ans;
    }
};