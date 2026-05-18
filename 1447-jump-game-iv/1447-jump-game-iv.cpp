class Solution {
public:
    int minJumps(vector<int>& arr) {
        // int n=arr.size();
        // if(n==1) return 0;
        // vector<int>dp(n,1e9-5);
        // dp[n-2]=1;
        // dp[n-1]=0;
        // for(int i=n-2;i>=0;--i)
        // {
        //     if(arr[i]==arr[n-1]) dp[i]=1;
        // }
        // map<int,vector<int>>rk;

        // for(int i=0;i<n;++i)
        // {
        //     rk[arr[i]].push_back(i);
        // }
        // for(int i=n-3;i>=0;--i)
        // {
        //     auto x=rk[arr[i]];
        //     int l=x.size();
        //     for(int j=0;j<l;++j)
        //     {
        //         if(x[j]!=i) dp[i]=min(dp[i],1+dp[x[j]]);
        //     }
        //     dp[i]=min(dp[i],1+dp[i+1]);
        //     if((i-1)>=0) dp[i]=min(dp[i],1+dp[i-1]);
        // }

        // for(int i=n-3;i>=0;--i)
        // {
        //     auto x=rk[arr[i]];

        //     int l=x.size();
        //     for(int j=0;j<l;++j)
        //     {
        //         if(x[j]!=i) dp[i]=min(dp[i],1+dp[x[j]]);
        //     }

        //     dp[i]=min(dp[i],1+dp[i+1]);
        //     if((i-1)>=0) dp[i]=min(dp[i],1+dp[i-1]);
        // }
        // // cout<<"\n";
        // // for(int i=0;i<n;++i) cout<<dp[i]<<" ";
        // return dp[0];

        int n = arr.size();
        unordered_map<int, vector<int>>rk;
        for (int i=0;i<n;++i) rk[arr[i]].push_back(i);
        
        queue<int>q;
        vector<bool>vis(n);
        q.push(0);
        int steps = 0;
        while(!q.empty())
        {
            int len=q.size();
            for(int j=0;j<len;++j)
            {
                int currIdx = q.front();
                q.pop();
                if (currIdx==n-1) return steps;
                if (currIdx + 1 < n && !vis[currIdx + 1])  
                {
                    vis[currIdx + 1] = true;
                    q.push(currIdx + 1);
                }
                if (currIdx - 1 >= 0 && !vis[currIdx - 1]) 
                {
                    vis[currIdx - 1] = true;
                    q.push(currIdx - 1);
                }
                for (auto &x : rk[arr[currIdx]])  
                {                                
                    if (!vis[x]) 
                    {
                        vis[x] = true;
                        q.push(x);
                    }
                }
                rk[arr[currIdx]].clear();  
            }
            steps++;
        }
        return -1;
    }
};