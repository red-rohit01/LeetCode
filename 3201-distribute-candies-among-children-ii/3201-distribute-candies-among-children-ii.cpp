class Solution {
public:
    // Here the DP based implementation would give us TLE as the TC would be O(4*n*limit) [limit for each of the dp[ind][n] ]
    long long helper(int ind,int n, int &limit,vector<vector<int>>&dp)
    {
        if(ind>3 && n==0) return 1;
        if(n<0) return 0;
        
        if(ind>3) return 0;
        
        if(dp[ind][n]!=-1LL) return dp[ind][n];
        
        long long ways=0;
        for(int i=0;i<=limit;++i)
        {
            if(n>=i) ways+=helper(ind+1,n-i,limit,dp);
        }
        return dp[ind][n]=ways;
    }

    long long distributeCandies(int n, int limit) {
        int total=3*limit;
        if(total<n) return 0;
        
        // long long ans=1LL*(n+2)*1LL*(n+1)/2;
        // long long val1=1LL*(n-limit+1);
        // long long val2=1LL*(n-2*limit);
        
        // if(val2>=2)
        // {
        //     long long curr=val2*(val2-1)/2;
        //     ans+=3* curr;
        // }
        
        // if(val1>=2)
        // {
        //     long long curr=val1*(val1-1)/2;
        //     ans-=3*curr;
        // }
        // return ans;

        // *DP based implementation*
        // vector<vector<long long>>dp(4,vector<long long>(n+2,-1LL));
        // return helper(1,n,limit,dp);

        // O(N) implementation
        // We want to (A+B+C)==n  
        // So we just use a for loop from [0, min(limit, n)] to traverse through all the possible values that B could attain and check accordingly.
        // If the candies left can be split into A and C then we need to find all possible ways to split them.
        // So we need to count all the possible ways to pick A and C in the range :
        // max(0,(n−B)−limit)≤A≤min(limit,(n−B))
        long long ans=0LL;
        long long mn_B=max(0LL,1LL*(n-2*limit));
        long long mx_B=min(limit,n);

        for(int i=mn_B;i<=mx_B;++i)
        {
            // This particular check ensures that A and C got the values in the limit constraints
            if((n-i)<=2*limit) // Now we are just finding the possible values for 'A' so the corresponding values for 'C' are always set.
            {
                long long lower_val=max(0LL,1LL*(n-i-limit));
                long long upper_val=min(1LL*limit,1LL*(n-i));

                ans+=(upper_val-lower_val)+1;
            }
        }
        return ans;
    }
};