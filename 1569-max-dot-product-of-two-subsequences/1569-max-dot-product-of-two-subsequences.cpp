class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));

        int pf=0,nf=0,ps=0,ns=0;
        int mn1=nums1[0];
        int mn2=nums2[0];
        for(int i=0;i<n;++i)
        {
            if(nums1[i]>0) pf++;
            else if(nums1[i]<0) nf++;
        }

        for(int i=0;i<m;++i)
        {
            if(nums2[i]>0) ps++;
            else if(nums2[i]<0) ns++;
        }

        if((pf==n && ns==m) || (ps==m && nf==n))
        {
            if(pf==n)
            {
                for(int i=0;i<n;++i) mn1=min(mn1,nums1[i]);

                for(int i=0;i<m;++i) mn2=max(mn2,nums2[i]);
            }

            if(ps==m)
            {
                for(int i=0;i<n;++i) mn1=max(mn1,nums1[i]);

                for(int i=0;i<m;++i) mn2=min(mn2,nums2[i]);
            }

            return mn1*mn2;
        }

        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                int temp=nums1[i-1]*nums2[j-1];
                dp[i][j]=max(dp[i-1][j-1]+temp,max(dp[i-1][j],dp[i][j-1]));
            }
        }

        return dp[n][m];
    }
};