class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<long long>>pre(m,vector<long long>(n));
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                pre[i][j]=1LL*mat[i][j];
                if(i>0) pre[i][j]+=pre[i-1][j];
                if(j>0) pre[i][j]+=pre[i][j-1];
                if(i>0 && j>0) pre[i][j]-=pre[i-1][j-1];
            }
        }

        int ans=0;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                int l=1;
                int h=min((n-j),(m-i));
                int temp=0;
                while(l<=h)
                {
                    int mid=l+(h-l)/2;
                    long long val=pre[i+mid-1][j+mid-1];
                    if(i>0) val-=pre[i-1][j+mid-1];
                    if(j>0) val-=pre[i+mid-1][j-1];
                    if(i>0 && j>0) val+=pre[i-1][j-1];

                    if(val<=1LL*threshold)
                    {
                        temp=mid;
                        l=mid+1;
                    }
                    else h=mid-1;
                }
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};