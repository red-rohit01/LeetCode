class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int col_l=n;
        int col_r=-1;
        int row_top=m;
        int row_b=-1;

        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]==1)
                {
                    col_l=min(col_l,j);
                    col_r=max(col_r,j);
                    row_top=min(row_top,i);
                    row_b=max(row_b,i);
                }
            }
        }

        int hor=col_r-col_l+1;
        int ver=row_b-row_top+1;

        return (hor*ver);
    }
};