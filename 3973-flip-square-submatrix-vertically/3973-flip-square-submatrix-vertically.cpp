class Solution {
public:
    // x+i represents the top row index
    // x+k−i−1 represents the bottom row index
    // y+j represents the current column
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i=0;i<(k/2);++i)
        {
            for(int j=0;j<k;++j) swap(grid[x+i][y+j],grid[x+k-i-1][y+j]);
        }

        return grid;
    }
};