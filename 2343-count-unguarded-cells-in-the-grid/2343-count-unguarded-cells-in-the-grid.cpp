class Solution {
public:
    //A cell can be guarded in only 4 directions, as we break our loop whenever we reach a guard in that 
    //specific direction. We can conclude that a cell is visited only at most 4 times (i.e by the nearest 
    //guard in the 4 directions). So you don't get TLE.

    // One of the other solution, I thought of is that since, we are supposed to break whenever we encounter
    // nearest wall or the end, then we can find the position of the nearest wall using Binary search 
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>v(m,vector<int>(n));
        int k=walls.size();
        for(int i=0;i<k;++i)
        {
            int x=walls[i][0], y=walls[i][1];
            v[x][y]=-2;
        }
        k=guards.size();
        for(int i=0;i<k;++i)
        {
            int x=guards[i][0], y=guards[i][1];
            v[x][y]=2;
        }
        for(int j=0;j<k;++j)
        {
            int x=guards[j][0], y=guards[j][1];
            for(int i=x-1;i>=0;i--)   //up
            { 
                if(v[i][y]==-2 || v[i][y]==2) break;
                v[i][y]=1;
            }
            for(int i=x+1;i<m;i++){ // down
                if(v[i][y]==-2 || v[i][y]==2) break;
                v[i][y] = 1;
            }
            for(int i=y-1;i>=0;i--){ // left
                if(v[x][i]==-2 || v[x][i]==2) break;
                v[x][i] = 1;
            }
            for(int i=y+1;i<n;i++){ // right
                if(v[x][i]==-2 || v[x][i]==2) break;
                v[x][i] = 1;
            }
        }
        int ans=0;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(v[i][j]==0) ans++;
            }
        }
        return ans;
    }
};