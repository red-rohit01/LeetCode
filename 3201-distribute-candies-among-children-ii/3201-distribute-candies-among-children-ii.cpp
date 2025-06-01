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
        // We can solve this in O(1) with the Inclusion-Exclusion Principle.
        // we subtract the number of distributions in which at least one child receives more than limit candies. 
        // However, in doing so, we may subtract some distributions multiple times - specifically, the ones where two or more children receive more than limit candies. 
        // To correct this, we add back the number of cases where at least two children exceed the limit.
        // But now we've overcounted the distributions where all three children exceed the limit, so we subtract those again.

        // a. three kids with any number of candies= (n+2)C2  
        // b. one kid with more than limit number of candies= n+2−(limit+1)C2
        // c. two kids with more than limit number of candies= n+2−2∗(limit+1)C2
        // d. three kids with more than limit number of candies= n+2−3∗(limit+1)C2
        // From the principle above, we get ans= 1∗a−3∗b+3∗c−d

        long long ans=1LL*(n+2)*1LL*(n+1)/2;    // Distributing 'n' candies among '3' children is same as placing two dividers. (n-r+1)C(r-1)  here r=3... n+2C2
        long long b_val=1LL*(n-limit+1);    
        long long c_val=1LL*(n-2*limit);
        long long d_val=1LL*(n-3*limit-1);

        if(b_val>=2)
        {
            long long val2=b_val*(b_val-1)/2;
            ans-=3*val2;
        }

        if(c_val>=2)
        {
            long long val3=c_val*(c_val-1)/2;
            ans+=3*val3;
        }

        if(d_val>=2)
        {
            long long val4=d_val*(d_val-1)/2;
            ans-=val4;
        }
        return ans;

        // *DP based implementation*
        // vector<vector<long long>>dp(4,vector<long long>(n+2,-1LL));
        // return helper(1,n,limit,dp);

        // O(N) implementation
        // We want to (A+B+C)==n  
        // So we just use a for loop from [0, min(limit, n)] to traverse through all the possible values that B could attain and check accordingly.
        // If the candies left can be split into A and C then we need to find all possible ways to split them.
        // So we need to count all the possible ways to pick A and C in the range :
        // max(0,(n−B)−limit)≤A≤min(limit,(n−B))

        // long long ans=0LL;
        // long long mn_B=max(0LL,1LL*(n-2*limit));
        // long long mx_B=min(limit,n);

        // for(int i=mn_B;i<=mx_B;++i)
        // {
        //     // Now we are just finding the possible values for 'A' so the corresponding values for 'C' are always set.
        //     long long lower_val=max(0LL,1LL*(n-i-limit));
        //     long long upper_val=min(1LL*limit,1LL*(n-i));
        //     ans+=(upper_val-lower_val)+1;        
        // }
        // return ans;
    }
};