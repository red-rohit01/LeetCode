class Solution {
public:
    int helper(int i,int n,vector<int>&coins,long long &amount,auto &dp,long long curr)
    {
        if(i==n)
        {
            if(curr==amount) return 0;
            
            return 1e9;
        }
        if(curr==amount) return 0;

        if(dp[i][curr]!=-1) return dp[i][curr];

        int not_taken=helper(i+1,n,coins,amount,dp,curr);

        int taken=1e9;
        if((curr+1LL*coins[i])<=amount)
        {
            taken=1+helper(i,n,coins,amount,dp,curr+coins[i]);
        }
        return dp[i][curr]=min(taken,not_taken);
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        
        long long target=1LL*amount;
        int ans=helper(0,n,coins,target,dp,0LL);
        if(ans==1e9) return -1;

        return ans; 
    }
};