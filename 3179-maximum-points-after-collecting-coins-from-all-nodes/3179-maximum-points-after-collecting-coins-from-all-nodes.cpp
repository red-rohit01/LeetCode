class Solution {
public:
    // Here idea is to check both of these possibilities to determine the maxm.
    // One of the smart move was to determine the dp state. Here we can see at each of the nodes I'll have different ways to arrive 
    // with any of the sum value. so, states could be dp[node][sum] but this sum could be very large and thus difficult to represent 
    // in 2-D dp.
    // Another way would be instead of sum, I can take help of the number of second type of operations taken to arrive at a particular 
    // node. 
    // since maxm value of coins[i] ==1e4 so, on division by values greater than (2^15) this would always be '0'.

    int helper(vector<int>adj[],int st,int p,vector<int>&coins,int &k,vector<vector<int>>&dp,int t)
    {
        if(t>15) return 0;
        if(dp[st][t]!=-1) return dp[st][t];

        int val1=(coins[st]>>t)-k;
        int val2=(coins[st]>>(t+1));

        for(auto &x:adj[st])
        {
            if(x!=p)
            {
                val1+=helper(adj,x,st,coins,k,dp,t);
                val2+=helper(adj,x,st,coins,k,dp,t+1);
            }
        }

        return dp[st][t]=max(val1,val2);
    }
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n=coins.size();
        vector<int>adj[n];
        for(int i=0;i<(n-1);++i)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>>dp(n,vector<int>(16,-1));
        int ans=helper(adj,0,-1,coins,k,dp,0);
        return ans;
    }
};