class Solution {
public:
    // Idea is to check for possibility if with pick/not_pick I can create the summation to each particular index value or not
    // Since, The constraints on the length of nums here are very small so, we can check in dp manner along with Binary search on the 
    // required value of 'k'
    bool check(vector<int>nums,vector<vector<int>>&queries,int mid)
    {
        int len=nums.size();
        for(int i=0;i<len;++i)
        {
            int curr=nums[i];

            vector<bool>dp(curr+1);
            dp[0]=1;

            for(int j=0;j<mid;++j)
            {
                int l=queries[j][0];
                int r=queries[j][1];
                int val=queries[j][2];

                if(l<=i && i<=r)
                {
                    for(int k=curr;k>=val;--k) dp[k]=(dp[k] || dp[k-val]);   //since each of the value is available for only one time.so, we'll traverse in reverse direction
                }
            }
            
            if(dp[curr]==0) return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int m=queries.size();

        int l=0, h=m;
        int ans=-1;

        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(check(nums,queries,mid))
            {
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};