class Solution {
public:
    const long long mod=12345;  // If '12345' would had been a prime number then we could have simply multiplied with the modinverse 

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m));
        vector<vector<int>>pre(n,vector<int>(m));
        vector<vector<int>>suff(n,vector<int>(m));
        
        int p=1;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                pre[i][j]=p;
                p=(p%mod * grid[i][j]%mod)%mod;
            }
        }
        p=1;
        for(int i=n-1;i>=0;--i)
        {
            for(int j=m-1;j>=0;--j)
            {
                suff[i][j]=p;
                p=(p%mod * grid[i][j]%mod)%mod;
            }
        }
        
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                ans[i][j]=(pre[i][j]%mod * suff[i][j]%mod)%mod;
            }
        }
        return ans;
    }
};