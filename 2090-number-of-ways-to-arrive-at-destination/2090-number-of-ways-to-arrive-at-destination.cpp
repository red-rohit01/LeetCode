class Solution {
public:
    const int mod=1000000007;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<int>ways(n,0);
        vector<long long>time(n,1e18);

        vector<pair<long long,long long>>adj[n];
        for(auto &x:roads)
        {
            adj[x[0]].push_back({x[2],x[1]});
            adj[x[1]].push_back({x[2],x[0]});
        }
       
        priority_queue<pair<long long,long long >,vector<pair<long long,long long>>,greater<pair<long long,long long >>>q;
        q.push({0,0});
        time[0]=0;
        ways[0]=1;
        while(!q.empty())
        {
            auto it=q.top();
            q.pop();
            long long node=it.second;
            long long prevtime=it.first;

            for(auto &x:adj[node])
            {
                long long weight=x.first;
                long long currnode=x.second;
                if((prevtime+weight) < time[currnode])
                {
                    time[currnode]=(prevtime+weight);
                    ways[currnode]=0;
                    ways[currnode]=(ways[currnode]%mod + ways[node]%mod)%mod;
                    q.push({(prevtime+weight),currnode});
                }
                else if((prevtime+weight) ==time[currnode])
                {
                    //time[currnode]=(prevtime+weight);
                    ways[currnode]=(ways[currnode]%mod + ways[node]%mod)%mod;
                    //q.push({(prevtime+weight),currnode});
                }
                
            }
        }
        return ways[n-1];
    }
};