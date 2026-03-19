class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<int>sumX(m),sumY(m);

        int ans=0;
        for(int i=0;i<n;++i)
        {
            int rx=0,ry=0;

            for(int j=0;j<m;++j)
            {
                if(grid[i][j]=='X') rx++;
                else if(grid[i][j]=='Y') ry++;

                sumX[j]+=rx;
                sumY[j]+=ry;

                if(sumX[j]>0 && sumX[j]==sumY[j]) ans++;
            }
        }
        return ans;
    }
};