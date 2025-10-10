class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        vector<int>dp(n);
        int ans=INT_MIN;
        for(int j=n-1;j>=0;--j)
        {
            dp[j]=energy[j];
            if((j+k)<n) dp[j]=dp[j+k]+energy[j];
            
            ans=max(ans,dp[j]);
        }
        return ans;
    }
};