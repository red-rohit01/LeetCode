class Solution {
public:
    // Making use of 2-D prefix sum but its Implementation is O(m*n*min(m,n))
    // Another approach: O(m*n)
    // Let's define dp[i][j]=maxm size of square ending at (i,j)
    // When i > 0 and j > 0, if matrix[i][j] = '0', then dp[i][j] = 0 since no square will be able to contain the '0' at that cell. 
    // If matrix[i][j] = '1', we will have dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1, which means that the square will 
    // be limited by its left, upper and upper-left neighbors.
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        // vector<vector<int>>pre(m+1,vector<int>(n+1));
        // for(int i=1;i<=m;++i)
        // {
        //     for(int j=1;j<=n;++j)
        //     {
        //         pre[i][j]=(pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1])+(matrix[i-1][j-1]-'0');
        //     }
        // }

        // int ans=0;
        // for(int i=1;i<=m;++i)
        // {
        //     for(int j=1;j<=n;++j)
        //     {
        //         if(matrix[i-1][j-1]=='0') continue;

        //         int mn=min(i,j);
        //         for(int len=1;len<=mn;++len)
        //         {
        //             int curr=(pre[i][j]-pre[i-len][j]-pre[i][j-len]+pre[i-len][j-len]);
        //             if(curr==(len*len))
        //             {
        //                 ans=max(ans,curr);
        //             }
        //         }
        //     }
        // }
        // return ans;

        vector<vector<int>>dp(m,vector<int>(n));
        int len=0;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(i==0 || j==0 || matrix[i][j]=='0') dp[i][j]=(matrix[i][j]-'0');

                else 
                {
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                }
                len=max(len,dp[i][j]);
            }
        }

        return (len*len);
    }
};