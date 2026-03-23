class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int mod=1e9+7;

        vector<vector<long long>>mx(m,vector<long long>(n)),mn(m,vector<long long>(n));
        mx[0][0]=mn[0][0]=grid[0][0];

        for(int i=1;i<m;++i) mx[i][0]=mn[i][0]=mx[i-1][0]*grid[i][0];    // left side

        for(int j=1;j<n;++j) mx[0][j]=mn[0][j]=mx[0][j-1]*grid[0][j];    // top side

        for(int i=1;i<m;++i)
        {
            for(int j=1;j<n;++j)
            {
                if(grid[i][j]<0)   // minimum_product x negative_number = maximum_product
                {
                    mx[i][j]=min(mn[i-1][j],mn[i][j-1])*grid[i][j];

                    mn[i][j]=max(mx[i-1][j],mx[i][j-1])*grid[i][j];
                }
                else              // maximum_product x positive_number = maximum_product
                {
                    mx[i][j]=max(mx[i-1][j],mx[i][j-1])*grid[i][j];

                    mn[i][j]=min(mn[i-1][j],mn[i][j-1])*grid[i][j];
                }
            }
        }

        int ans=mx[m-1][n-1]%mod;

        if(ans<0) return -1;
        return ans;
    }
};