class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>temp=matrix;
        for(int j=0;j<n;++j)
        {
            for(int i=1;i<m;++i)
            {
                if(matrix[i][j]!=0)
                {
                    temp[i][j]=temp[i-1][j]+1;
                }
            }
        }

        int ans=0;
        for(int i=0;i<m;++i)
        {
            vector<int>rk(n);
            for(int j=0;j<n;++j)
            {
                rk[j]=temp[i][j];
            }
            sort(rk.begin(),rk.end());

            for(int j=0;j<n;++j)
            {
                if(rk[j]!=0)
                {
                    int cnt=(n-j);
                    int val=cnt*rk[j];
                    ans=max(ans,val);
                }
            }
        }
        return ans;
    }
};