class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long n=nums.size();

        long long leftst=-1;     //starting index of the subarray
        long long mnind=-1,mxind=-1;
        long long ans=0;
        
        for(long long i=0;i<n;++i)
        {
            if(nums[i]>=minK && nums[i]<=maxK)
            {
                mnind=(nums[i]== minK)?i:mnind;
                mxind=(nums[i]==maxK)?i:mxind;

                ans+=max(0ll,min(mnind,mxind)-leftst);// This min(mnind,mxind)-leftst counts the no. of starting point previous from actual [minK,maxK] as we can include all of them. 
            }        // e.g., [1,1,2,3,5,2,7,5] and minK=2, maxK=5. Actual 1st subarray under consideration is from index {2,4} but we can include the previous
                    // 0 and 1 index too. The 2nd subarray under consideration is from index [2,5] then, again we can include the previous '0' and '1' too.
            else 
            {
                leftst=i;
                mnind=-1;
                mxind=-1;
            }
        }
        return ans;
    }
};