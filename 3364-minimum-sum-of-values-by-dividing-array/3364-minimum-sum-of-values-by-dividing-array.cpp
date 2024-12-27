class Solution {
public:
    // Here we can observe that we can have repeating state for [i][j][curr_and]. Here 'i' --> index no. on nums vector
    // 'j' --> index no. on andValues vector and 'curr_and' --> curr & values of all the elements under consideration.
    // It's giving TLE with 'dp' implementation
    // vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(mx_and+1,-1)));
    // so, we'll use unordered_map based 'dp'
    
    int helper(int i,int &n,int j, int &m,vector<int>&nums,vector<int>&andValues,int curr_and,auto &dp)
    {
        if(i==n)
        {
            if(j==m) return 0;
            else return 1e8;
        }
        else if(j==m) return 1e8;

        //if(dp[i][j][curr_and]!=-1) return dp[i][j][curr_and];

        if(dp[i][j].count(curr_and)) return dp[i][j][curr_and];

        int include=1e8;
        if((curr_and&nums[i])==andValues[j]) 
        {
            include=nums[i]+helper(i+1,n,j+1,m,nums,andValues,((1<<17)-1), dp);
        }

        int exclude=helper(i+1,n,j,m,nums,andValues, curr_and&nums[i],dp);

        return dp[i][j][curr_and]=min(include,exclude);

    }
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int n=nums.size();
        int m=andValues.size();
        int mx_and=((1<<17)-1);
        //vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(mx_and+1,-1)));

        vector<vector<unordered_map<int,int>>>dp(n,vector<unordered_map<int,int>>(m));
        
        int curr_and=((1<<17)-1);   // Here the maximum possible nums[i] value is 1e5 so, It's upper limit is 2^17 -1
        
        int ans=helper(0,n,0,m,nums,andValues,curr_and, dp);
        if(ans==1e8) return -1;
        return ans;
    }
};