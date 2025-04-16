class Solution {
public:
    // When add a new number A[j] at the right of the window,
    // we already have count[A[j]] elements with value A[j] in the window,
    // so we will have count[A[j]] more pairs.
    // or If we have count of a particular element is 'c' then It'll contribute 'c-1' pairs

    // We'll count the number of invalid subarrays and then subtract it from total
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size();
        map<long long,long long>rk;
        long long l=0,h=0;
        long long ans=0;    // Count of subarrays having <k pairs
        long long same_elements_pair_cnt=0;
        while(h<n)
        {
            if(rk.find(nums[h])!=rk.end()) same_elements_pair_cnt+=rk[nums[h]];
            
            rk[nums[h]]++;
            
            while(l<=h && same_elements_pair_cnt>=k)
            {
                if(rk[nums[l]]>1) same_elements_pair_cnt-=(rk[nums[l]]-1);
                
                rk[nums[l]]-=1;
                l++;
            }
            ans+=(h-l+1);           // count of subarrays ending at index 'h'
            h++;
        }
        return (1LL*n*(n+1)/2) - ans;
    }
};