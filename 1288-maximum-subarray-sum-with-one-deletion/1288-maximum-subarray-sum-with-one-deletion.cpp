class Solution {
public:
        int maximumSum(vector<int>& arr) {
        int size = arr.size();
        if (size==1) return arr[0];

		// // dropped record the maximum sum ended at current index with one number being dropped
        // int dropped=max(arr[0],arr[1]);
        // // not dropped must take arr[1] at index = 1
        // int notDropped=max(arr[0]+arr[1],arr[1]);
        // int ans=max(dropped,notDropped);
            
        // for ( int i = 2; i < size; i++ ) 
        // {
        //     dropped = max( notDropped, arr[ i ] + dropped );
        //     notDropped = max( notDropped + arr[ i ], arr[ i ] );
        //     ans = max( ans, max( dropped, notDropped ) );
        // }
        // return ans;

        int n=size;
        vector<vector<int>>dp(n,vector<int>(2));
        dp[0][0]=arr[0];
        dp[0][1]=0;
        int total=arr[0];
        int ans=arr[0];

        for(int i=1;i<n;++i)
        {
            total+=arr[i];
            dp[i][0]=max(dp[i-1][0]+arr[i],arr[i]);
            dp[i][1]=max(dp[i-1][1]+arr[i],dp[i-1][0]);
            ans=max({ans,dp[i][0],dp[i][1]});
        }
        return ans;
    }
};