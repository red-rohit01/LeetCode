class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<pair<int,int>>dp(n);            // Instead of pair, Better would have been to use two different vector. One for parent and other for length
        for(int i=0;i<n;++i) dp[i]={1,i};
        for(int i=1;i<n;++i)
        {
            for(int j=i-1;j>=0;--j)
            {
                if(nums[i]%nums[j]==0)
                {
                    if(dp[i].first<(1+dp[j].first))
                    {
                        dp[i]={1+dp[j].first,j};
                    }
                }
            }
        }
        vector<int>ans;

        int mx=dp[0].first;
        int ind=dp[0].second;
        
        for(int i=1;i<n;++i)
        {
            if(dp[i].first>mx)
            {
                mx=dp[i].first;
                ind=i;
            }
        }

        while(mx--)
        {
            ans.push_back(nums[ind]);
            ind=dp[ind].second;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};