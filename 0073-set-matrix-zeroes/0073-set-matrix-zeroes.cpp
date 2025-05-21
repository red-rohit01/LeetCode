class Solution {
public:
    // For in place and w/o any extra space. The idea is to use the first row and first column as indication.
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int row_flag=1;
        int col_flag=1;

        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(matrix[i][j]==0)
                {
                    if(i==0) row_flag=0;
                    else matrix[i][0]=0;

                    if(j==0) col_flag=0;
                    else matrix[0][j]=0;
                }
            }
        }

        for(int i=1;i<n;++i)
        {
            for(int j=1;j<m;++j)
            {
                if(matrix[0][j]==0 || matrix[i][0]==0) matrix[i][j]=0;
            }
        }
    
        for(int j=0;j<m;++j)
        {
            if(row_flag==0) matrix[0][j]=0;
        }

        for(int i=0;i<n;++i)
        {
            if(col_flag==0) matrix[i][0]=0;
        }
    }
};