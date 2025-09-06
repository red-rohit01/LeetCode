class Solution {
public:
    // 4^16 > 1e9 [16 can be our limit for multiples of '4']
    // To reduce a number n to 0 by repeated division by say x we need floor(logₓn) + 1 operations. So we can group numbers based on the no. of operations they need.
    // All numbers in [1, 3] (i.e., from 4⁰ to 4¹ - 1) require 1 division.
    // All numbers in [4, 15] (i.e., from 4¹ to 4² - 1) require 2 divisions.
    // All numbers in [16, 63] (i.e., from 4² to 4³ - 1) require 3 divisions.

    long long minOperations(vector<vector<int>>& queries) {
        long long ans=0;
        int n=queries.size();
        for(int i=0;i<n;++i)
        {
            long long start=queries[i][0];
            long long end=queries[i][1];

            long long op=0;
            for(long long d=1,prev=1;d<=16;++d)   // Here 'd' is the log4 based iteration number and prev is the number of elements in last group
            {
                long long curr=prev*4;             // No. of elements in the current iteration of multiples of '4'
                long long l=max(start,prev);
                long long r=min(end,curr-1);

                if(r>=l) op+=(r-l+1)*d;

                if(curr>end) break;
                prev=curr;
            }
            ans+=(op+1)/2;     // Since, we are allowed to choose a pair to perform the operation
        }
        return ans;
    }
};