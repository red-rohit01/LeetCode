class Solution{
    public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> ROW_SUMS(grid), COL_SUMS(grid), DIAG_SUMS(grid), DIAG2_SUMS(grid);
        for(int row = 0; row < m; row++) 
            for(int col = 0; col < n; col++) {
                if(col - 1 >= 0)                 ROW_SUMS[row][col]   += ROW_SUMS[row][col - 1];
                if(row - 1 >= 0)                 COL_SUMS[row][col]   += COL_SUMS[row - 1][col];
                if(row - 1 >= 0 && col - 1 >= 0) DIAG_SUMS[row][col]  += DIAG_SUMS[row - 1][col - 1];
                if(row - 1 >= 0 && col + 1 < n)  DIAG2_SUMS[row][col] += DIAG2_SUMS[row - 1][col + 1];
            }
        
        for(int sz=min(m,n);sz>1;sz--)              // start from max-sized square
            for(int row=0;row<=m-sz;row++)         // iterate over all starting row index for sqaure of side=sz
                for(int col=0;col<=(n-sz);col++) {   // iterate over all starting col index for sqaure of side=sz
                    bool flag=true;
                    // check if sum of both diagonals of current square is equal
                    int diag_sum=DIAG_SUMS[row+sz-1][col+sz-1]-(row-1>=0 && col-1>=0?DIAG_SUMS[row-1][col-1]:0),
                    anti_diag_sum=DIAG2_SUMS[row+sz-1][col]-(row-1>=0 && col+sz<n?DIAG2_SUMS[row-1][col+sz]:0);
                    if(diag_sum != anti_diag_sum) flag=false;
                    // check if sum of all rows and columns are equal -- reduced to O(sz) from O(sz^2) in previous approach
                    for(int i = 0; flag && i < sz; i++) 
                        if(diag_sum != ROW_SUMS[row + i][col + sz-1] - (col - 1 >= 0 ? ROW_SUMS[row + i][col - 1] : 0) ||  
                        diag_sum != COL_SUMS[row + sz-1][col + i] - (row - 1 >= 0 ? COL_SUMS[row - 1][col + i] : 0)) flag = false;
                    if(flag) return sz;     // flag hasn't been reset meaning all row/col/diag sums are equal, so return current size           
                }
        return 1;   
    }
};