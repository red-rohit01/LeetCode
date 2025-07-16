class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<vector<int>>dp(2,vector<int>(2));   // Here dp[i][j] --> length of max subsequence when curr_remainder=i
        for(int i=0;i<n;++i)       // ans last_remainder in the subsequence is 'j'. This is necessary when for curr num 
        {                          // remainder is '5' and chosen '3' as the last remainder. Then, we can only those values 
            int rem=(nums[i]%2);                               // from '3' having '5' as the remainder.
            dp[rem][1^rem]=max(dp[rem][1^rem], 1+ dp[1^rem][rem]);   // When we are considering alternating

            ans=max(ans,dp[rem][1^rem]);

            dp[rem][rem]=dp[rem][rem]+1;    // when cases like '0000' '1111'
            
            ans=max(ans,dp[rem][rem]);
        }
        return ans;
    }
};