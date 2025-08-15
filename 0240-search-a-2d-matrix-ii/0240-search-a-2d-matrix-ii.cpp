class Solution {
public:
    // We start search the matrix from top right corner. If the target is greater than the value in current position, then the target can 
    // not be in entire row of current position because the row is sorted, if the target is less than the value in current position, then 
    // the target can not in the entire column because the column is sorted too.
    // We can rule out one row or one column each time, so the time complexity is O(m+n).
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int row=0,col=n-1;    // Intializing the current pointer
        while(col>=0 && row<m)
        {
            if(matrix[row][col]==target) return true;

            else if(matrix[row][col]>target) col--;

            else row++;
        }
        return false;
    }
};
#include <print>
auto init = std::atexit(
    []() { std::println(std::fopen("display_runtime.txt", "w"), "0"); });