class Solution {
public:
    // The idea is explore all possibilities
    // For any given index we have 5 possibilities :
    // Apply only Operation-1
    // Apply only Operation-2
    // Apply Opertation-1 ===> Then ===> Apply Operation-2
    // Apply Operation-2 ===> Then ===> Apply Operation-1
    // Don't apply any operation
    int helper(vector<int>&nums,int &k,int idx,int &n,auto &dp,int op1,int op2)
    {
        if(idx==n) return 0;

        if(dp[idx][op1][op2]!=-1) return dp[idx][op1][op2];

        int ans=1e9;
        if(op1!=0)  // case-1
        {
            int sm=((nums[idx]+1)/2) + helper(nums,k,idx+1,n,dp,op1-1,op2);
            ans=min(ans,sm);
        }

        if(op2>0 && nums[idx]>=k) // case-2
        {
            int sm=(nums[idx]-k) + helper(nums,k,idx+1,n,dp,op1,op2-1);
            ans=min(ans,sm);
        }

        if(op1>0 && op2>0)
        {
            int curr=(nums[idx]+1)/2;

            //Case-3
            if(curr>=k)
            {
                int sum=(curr-k)+ helper(nums,k,idx+1,n,dp,op1-1,op2-1);
                ans=min(ans,sum);
            }

            //Case-4
            if(nums[idx]>=k)
            {
                int sum=(nums[idx]-k+1)/2 + helper(nums,k,idx+1,n,dp,op1-1,op2-1);
                ans=min(ans,sum);
            }
        }

        //case-5
        int no_opr=nums[idx]+helper(nums,k,idx+1,n,dp,op1,op2);

        ans=min(ans,no_opr);

        return (dp[idx][op1][op2]=ans);
    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(op1+1,vector<int>(op2+1,-1)));

        return helper(nums,k,0,n,dp,op1,op2);

    }
};