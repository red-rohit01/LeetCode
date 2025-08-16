class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n=nums.size();
        // /*
        //                 dp[1]       /dp[3]
        //                /  \        /
        //               /    \      /
        // ---dp[0]---- /     dp[2]
        

        // dp[0] = start phase
        // dp[1] = 1st increaseing phase
        // dp[2] = 1st decreaseing phase
        // dp[3] = 2nd increasing
        // */
        // long long ans=-1e18;
        // vector<vector<long long>>dp(4,vector<long long>(n,-1e18));

        // for(int i=0;i<n;++i)
        // {
        //     dp[0][i]=1LL*nums[i];

        //     if(i>0)
        //     {
        //         // start increasing phase here OR we are already in increasing phase
        //         if(nums[i]>nums[i-1]) dp[1][i]=max(dp[0][i-1]+nums[i], dp[1][i-1]+nums[i]);

        //         // start decreasing phase here OR continue the decreasing phase from previous
        //         if(nums[i]<nums[i-1]) dp[2][i]=max(dp[1][i-1]+nums[i], dp[2][i-1]+nums[i]);

        //         // start 2nd increasing phase from here OR continue the increasing phase from previous
        //         if(nums[i]>nums[i-1]) dp[3][i]=max(dp[2][i-1]+nums[i], dp[3][i-1]+nums[i]);
        //     }
        //     ans=max(ans,dp[3][i]);
        // }
        // return ans;

        // Approach 2:
        /*
        pref represents the prefix sum

        inc[i] represents maximum length of increasing subarray starting at i

        dec[i] represents maximum length of decreasing subarray starting at i

        ct1 represents current count of increasing subarray length

        ct2 represents current count of decreasing subarray length

        r1 is the start index of the last increasing segment

        r2 is the end index of the last increasing segment

        For every index l, we can find p and q
        p is valid only if inc[l] > 1
        q is valid only if dec[p] > 1
        */

        vector<long long>pre(n);
        pre[0]=1LL*nums[0];
        for(int i=1;i<n;++i) pre[i]=pre[i-1]+ 1LL*nums[i];

        vector<int>inc(n,1);
        vector<int>dec(n,1);

        int cnt1=1;          // represents the current count of increasing subarray
        int cnt2=1;          // represents the current count of decreasing subarray
        for(int i=n-2;i>=0;--i)
        {
            if(nums[i]<nums[i+1])
            {
                cnt1++;
                cnt2=1;
            }
            else if(nums[i]>nums[i+1])
            {
                cnt2++;
                cnt1=1;
            }
            else 
            {
                cnt1=1;
                cnt2=1;
            }
            inc[i]=cnt1;
            dec[i]=cnt2;
        }

        long long ans=-1e18;

        for(int l=0;l<n-3;++l)
        {
            if(inc[l]>1)
            {
                int p=l+inc[l]-1;
                if(dec[p]>1)
                {
                    int q=p+dec[p]-1;
                    if(inc[q]>1)
                    {
                        int r1=q+1;     //for these cases 1(l), 2,3(p), -5,-8(q), -3, -2,1  --> Here post q it's increasing but not beneficial to cover till '1'
                        int r2=q+inc[q]-1;

                        long long sum1=pre[r1];
                        if(l>0) sum1-=pre[l-1];

                        long long sum2=pre[r2];
                        if(l>0) sum2-=pre[l-1];

                        long long curr=max(sum1,sum2);
                        ans=max(ans,curr);
                    }
                }
            }
        }
        return ans;
    }
};