class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        long long n=nums.size();
        sort(nums.begin(),nums.end());
        long long ans=1;
        unordered_map<long long,long long>freq;
        for(auto &x:nums) freq[x]++;

        long long left=0;
        long long right=0;

        // First check: checking an existing number as the candidate 
        for(long long mid=0;mid<n;++mid)
        {
            while(nums[mid]-nums[left]>k) left++;

            while(right<n && (nums[right]-nums[mid])<=k) right++;

            long long total=right-left;
            long long curr=freq[nums[mid]]+min(1LL*numOperations,total-freq[nums[mid]]);
            ans=max(ans,curr);
        }

        // Second Check: It's bit tricky here. It's checking any of the midway element to be the candidate as in case of this TC:
        // [13,13,20,20], numOperations=4, k=4. Here suitable candidate is '17'. 
        // Here in this scenario: For any choosen element, num[right] would act as the right endpolong long of the window. so, left element 
        // would be 2*k distance away.

        left=0;
        for(right=0;right<n;++right)
        {
            while(1LL*nums[left]+2LL*k<1LL*nums[right]) left++;

            ans=max(ans,min(1LL*numOperations, right-left+1));
        }
        return ans;
    }
};