class Solution {
public:
    // Idea here is to calculate the reverse i.e., have total number of subsets and from that remove the count of subsets having sum
    // of elements less than k (i.e., sum ==k-1, k-2,k-3,....,1)

    /*   Suppose we partitioned our array into subsets s1 and s2 :-
            Final subsets -> s1 and s2
            condition to be satisfied :  s1 >= k and s2 >= k
            s1+s2 >= 2*k
            s1+s2 = sum of array = s
            
            so sum of array i.e s must be >= 2*k
            Converse of the above condition : s1>=k and s2>=k is:
            (1) s1<k and s2<k
            (2) s1<k and s2>=k
            (3) s1>=k and s2<k
            
            Now (1) will never occur because s1+s2>=2*k always 
            
            so we only need to find count in (2) and (3) respectively and we can subtract with total number of partitions = (2^n) where n is the size of the array.
            Now count in (2) = count in (3)
            because since s1+s2 >= 2*k , if one subset has sum <k the other subset will 
            have sum >=k
            
            So just find (2) using subset sum DP 
            Final ans=2^n-count in (2)-count in (3)
                     =2^n-2*(count in (2))    [as count in (2)=count in (3)]
*/
    const long long mod=1e9+7;
    long long modexpo(long long a, long long b) {
        if (b == 0)
            return 1;
        long long p = modexpo(a, b / 2) % mod;
        p = (p * p) % mod;
        return (b % 2 == 0) ? p : (a * p) % mod;
    }

    int countPartitions(vector<int>& nums, int k) {
        int n=nums.size();
        long long total=modexpo(2,n);   // total ways of partitioning the array into two partitions
        total-=2;     // Removing the empty case

        long long sum=0;
        for(auto &x:nums) sum+=1LL*x;

        if((2*k)>sum) return 0;
        vector<vector<long long>>dp(n,vector<long long>(k));  // dp[i][j]--> count of subsets with the first 'i' elements such that the sum of the subset equals 'j'

        dp[0][0]=1;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<k;++j)
            {
                if(i==0)
                {
                    if(j==nums[i]) dp[i][j]=1;
                    continue;
                }

                dp[i][j]=dp[i-1][j];

                if(nums[i]<=j)
                {
                    dp[i][j]=(dp[i][j]%mod + dp[i-1][j-nums[i]]%mod)%mod;
                }
            }
        }

        long long less=0;  // Count of subsets having lesser values.
        for(int j=1;j<k;++j) less+=dp[n-1][j];

        less%=mod;

        total=(total%mod - (2*less)%mod + mod)%mod;
        return total;
    }
};