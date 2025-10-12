class Solution {
public:
    int beautifulSplits(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return 0;

        vector<vector<int>>dp(n+1,vector<int>(n+1)); //Here dp[i][j] represents the length of array starting from index 'i' that matches the array starting from index 'j'

        for(int i=n-1;i>=0;--i)
        {
            for(int j=i;j<n;++j)
            {
                if(nums[i]==nums[j]) dp[i][j]=1+dp[i+1][j+1];
            }
        }

        int ans=0;
        // num1=={0,i} 
        // num2=={i+1,j}
        // num3=={j+1,n-1}
        for(int i=0;i<n-2;++i)
        {
            for(int j=i+1;j<n-1;++j)
            {
                if((i+1<=j-i && dp[0][i+1]>=i+1) || (j-i<=n-j && dp[i+1][j+1]>=(j-i))) ans++;
            }
        }
        return ans;
    }
};