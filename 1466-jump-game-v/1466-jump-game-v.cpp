class Solution {
public:
    int helper(int st,vector<int>&arr,int d,int n,vector<int>&dp)
    {
        if(dp[st]!=-1) return dp[st];

        dp[st]=0;
        for(int j=st-1;j>=0 && arr[j]<arr[st] && (j>=(st-d));--j)
        {
            dp[st]=max(dp[st],1+helper(j,arr,d,n,dp));
        }
        for(int j=st+1;j<n && arr[j]<arr[st] && (j<=(st+d));++j)
        {
            dp[st]=max(dp[st],1+helper(j,arr,d,n,dp));
        }
        return dp[st];
    }
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        vector<int>dp(n,-1);
        int mx=1;
        for(int i=0;i<n;++i)
        {
            mx=max(mx,1+helper(i,arr,d,n,dp));
        }
        return mx;
    }
};