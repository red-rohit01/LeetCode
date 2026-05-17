class Solution {
public:
    void helper(int start,vector<int>&arr,int n,vector<int>&dp)
    {
        dp[start]=1;
        if(arr[start]==0) return;
        
        int val1=start-arr[start];
        if(val1>=0 && dp[val1]==0) helper(val1,arr,n,dp);

        int val2=start+arr[start];
        if(val2<n && dp[val2]==0) helper(val2,arr,n,dp);
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        bool flag=false;
        vector<int>dp(n);
        for(int i=0;i<n;++i)
        {
            if(arr[i]==0) 
            {
                flag=true;
            }
        }
        if(flag==false) return false;
        
        helper(start,arr,n,dp);
        for(int i=0;i<n;++i)
        {
            if(arr[i]==0 && dp[i]==1) return true;
        }
        return false;
    }
};