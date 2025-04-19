class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        vector<vector<int>>pre(m+1,vector<int>(n+1));
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                pre[i][j]=(pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1])+(matrix[i-1][j-1]-'0');
            }
        }

        int ans=0;
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(matrix[i-1][j-1]=='0') continue;

                int mn=min(i,j);
                for(int k=1;k<=mn;++k)
                {
                    int curr=(pre[i][j]-pre[i-k][j]-pre[i][j-k]+pre[i-k][j-k]);
                    if(curr==(k*k))
                    {
                        ans=max(ans,curr);
                    }
                }
            }
        }
        return ans;
    }
};