class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    void bfs(vector<vector<int>>& heights,int m,int n,queue<pair<int,int>>&src,vector<vector<bool>>& matrix)
    {
        while(!src.empty())
        {
            int x=src.front().first;
            int y=src.front().second;
            src.pop();
            for(int i=0;i<4;++i)
            {
               int newx=x+dx[i];
               int newy=y+dy[i];
                
                //checking the boundary
                if(newx<0 || newx>=m || newy<0 || newy>=n || matrix[newx][newy]==true)
                {
                    continue;
                }
                //marking 
                if(heights[x][y]<=heights[newx][newy])
                {
                    matrix[newx][newy]=true;
                    src.push({newx,newy});
                }
            }
        }
        
    } 
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>&heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<bool>>pmatrix(m,vector<bool>(n,false)); // pmatrix means visiting matrix for pacific ocean
        vector<vector<bool>>amatrix(m,vector<bool>(n,false)); 
        
        queue<pair<int,int>>psrc,asrc;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 || j==0)
                {
                    psrc.push({i,j});
                    pmatrix[i][j]=true;
                }
                
                if(i==m-1 || j==n-1)
                {
                    asrc.push({i,j});
                    amatrix[i][j]=true;
                }
            }
        }
        bfs(heights,m,n,psrc,pmatrix);
        bfs(heights,m,n,asrc,amatrix); 
    
        vector<vector<int>>ans;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(pmatrix[i][j] && amatrix[i][j])
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};