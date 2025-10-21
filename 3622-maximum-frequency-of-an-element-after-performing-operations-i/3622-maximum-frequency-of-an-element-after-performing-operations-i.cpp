class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=1;
        unordered_map<int,int>freq;
        for(auto &x:nums) freq[x]++;

        int left=0;
        int right=0;

        // First check: checking an existing number as the candidate 
        for(int mid=0;mid<n;++mid)
        {
            while(nums[mid]-nums[left]>k) left++;

            while(right<n && (nums[right]-nums[mid])<=k) right++;

            int total=right-left;
            int curr=freq[nums[mid]]+min(numOperations,total-freq[nums[mid]]);
            ans=max(ans,curr);
        }

        // Second Check: It's bit tricky here. It's checking any of the midway element to be the candidate as in case of this TC:
        // [13,13,20,20], numOperations=4, k=4. Here suitable candidate is '17'. 
        // Here in this scenario: For any choosen element, num[right] would act as the right endpoint of the window. so, left element 
        // would be 2*k distance away.

        left=0;
        for(right=0;right<n;++right)
        {
            while(nums[left]+2*k<nums[right]) left++;

            ans=max(ans,min(numOperations, right-left+1));
        }
        return ans;
    }
};