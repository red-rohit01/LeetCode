class Solution {
public:
    // int helper(int i,int &n,int curr,vector<int>&rewardValues,auto &dp)
    // {
    //     if(curr>(5*1e4))
    //     {
    //         return 0;
    //     }

    //     if(i==n)
    //     {
    //         return 0;
    //     }

    //     if(dp[i].count(curr)) return dp[i][curr];

    //     int exclude=helper(i+1,n,curr,rewardValues,dp);

    //     int include=0;
    //     if(rewardValues[i]>curr) include=rewardValues[i]+helper(i+1,n,curr+rewardValues[i],rewardValues,dp);

    //     return dp[i][curr]=max(include,exclude);
    // }
    int maxTotalReward(vector<int>& rewardValues) {
        // set<int>st(rewardValues.begin(),rewardValues.end());
        // vector<int>temp(st.begin(),st.end());
        // int n=temp.size();
        // // int ans=0;
        // int curr=0;
        // vector<unordered_map<int,int>>dp(n,unordered_map<int,int>());

        // return helper(0,n,curr,temp,dp);
        
        sort(rewardValues.begin(), rewardValues.end());
        int n=rewardValues.size();
        bool dp[50000]={};
        dp[0]=true;
        int maximum_reward=0;
        for (int i=0;i<n;++i) 
        {
            if (i==0 || rewardValues[i-1]!=rewardValues[i]) 
            {
                int limit=min(rewardValues[i], rewardValues[n-1]-rewardValues[i]);
                for (int j=0;j<limit;++j) 
                {
                    if (dp[j]) 
                    {
                        dp[j+rewardValues[i]] = true;
                        maximum_reward = max(maximum_reward, j + rewardValues[i]);
                    }
                }
            }
        }
        return (maximum_reward+rewardValues[n - 1]);
    }
};