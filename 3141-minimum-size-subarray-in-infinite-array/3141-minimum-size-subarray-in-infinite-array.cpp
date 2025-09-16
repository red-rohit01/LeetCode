class Solution {
public:
    // Notice that, target is either: A subarray of nums, or suffix_sum[i] +  k * sum(nums)  + prefix_sum[j] for some i, j, k.
    // This problem can be boiled down to length of shortest subarray for a particular sum in case of circular array.

    // Good TC to understand the working of this code: [1,2,3], target=21    || [1,2,3], target=22
    int minSizeSubarray(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>temp=nums;
        for(int i=0;i<n;++i) temp.push_back(nums[i]);

        vector<long long>pre(2*n);
        pre[0]=temp[0];

        map<long long,long long>rk;   // rk[a]=b   || It represent the index 'b' to have prefix sum equal to 'a'
        rk[temp[0]]=0;
        for(int i=1;i<2*n;++i)
        {
            pre[i]=pre[i-1] + 1LL*nums[i%n];
            rk[pre[i]]=i;
        }

        long long total=pre[n-1];
        int ans=((1LL*target)/total)*n;     // 'ans' represents the total number of full 'nums' required to be included 
        target%=total;
        if(target==temp[0]) 
        {
            ans++;
            return ans;
        }
        int val=INT_MAX;
        
        // This essentially covers the minimum length to get the particular remaining target sum
        for(int i=1;i<2*n;++i)
        {
            if(pre[i]<target) continue;

            long long rem=pre[i]-target;
            if(rk.find(rem)!=rk.end())
            {
                int len=i-rk[rem];
                val=min(val,len);
            }
        }
        if(val==INT_MAX) return -1;
        return (ans+val);
    }
};