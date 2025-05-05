class Solution {
public:
    // It's the extension of Minimum/Maximum non-adjacent sum path in a tree  
    // GFG Link: https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

    // A trip has unique path beacause of the graph is a tree. That's why we can use "demand" to simplify the trip cost. The total 
    // cost is of summation of demand[i] * cost[i] or demand[i] * cost[i] / 2 .
    // Then, it's time to decide which node we should half the price. And it leads us to make use of dynamic programming

    // fill demand in terms of how many times current node will be vistited in all trips
    // since it's a tree there will be unique path only from 'st' to 'en'
    bool path(int st,int en, int p,vector<int>adj[],vector<int>& demand)
    {
        if(st==en)
        {
            demand[en]++;
            return true;
        }

        for(auto &x:adj[st])
        {
            if(x!=p)
            {
                if(path(x,en,st,adj,demand))
                {
                    demand[st]++;
                    return true;
                }
            }
        }
        return false;
    }
    // Pair represents: minimum sum with {current Node halved, current node not halved}
    // Observations: If you halve the current node then you cannot halve its adjcent)
    pair<int,int> minNonAdjacentPath(int u,int p,vector<int>adj[],vector<int>&demand,vector<int>&price)
    {
        int consider_half=(price[u]/2)*demand[u];
        int not_half=price[u]*demand[u];

        for(auto &x:adj[u])
        {
            if(x!=p)
            {
                auto temp=minNonAdjacentPath(x,u,adj,demand,price);

                // Take minimum of both consider and not consider case of childs
                not_half+=min(temp.first,temp.second);

                // You can only take values where child node is not halved
                consider_half+=temp.second;
            }
        }
        return {consider_half,not_half};
    }
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<int>adj[n];
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int>demand(n+1);
        int m=trips.size();
        for(int i=0;i<m;++i)
        {
            int st=trips[i][0];
            int en=trips[i][1];

            path(st,en,-1,adj,demand);
        }

        auto ans=minNonAdjacentPath(0,-1,adj,demand,price);
        return min(ans.first,ans.second);
    }
};