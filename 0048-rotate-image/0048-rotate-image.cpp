class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        // swapping the values about the principal diagonal
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        // Now reversing each of the row
        for(int l=0;l<n;l++)
        {
            int i=0,j=n-1;
            while(i<j)
            {
                swap(matrix[l][i],matrix[l][j]);
                i++;
                j--;
           }
        }
    }
};