class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=0;
        for(auto &x:nums) sum+=x;
        sum-=x;      // Remaining elements sum
        if(sum<0) return -1;

        int i=0;
        int curr=0;
        int rem=INT_MIN;
        int j=0;
        while(j<n)
        {
            curr+=nums[j]; 
            while(i<=j && curr>sum)
            {
                curr-=nums[i];
                i++;
            }
            if(curr==sum) rem=max(rem,j-i+1);
            j++;
        }
        return rem==INT_MIN?-1:(n-rem);
    }
};