class Solution {
public:
    // By looking at how OR works, we can see that bits can only be turned on with 1. 
    // So, start from the end and keep track of the minimum index that will keep the bit set. 
    // Then, take the maximum of all the indexes that contain set bits.
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,1);
        vector<int>latest(31);
        for(int i=n-1;i>=0;--i)
        {
            for(int j=0;j<31;++j)      // so, later on we would get the most significant bit.Even if there is one single bit at a
            {                          // very later index. I would have to take that to get the maximum OR value
                if(nums[i]&(1<<j)) latest[j]=i;

                res[i]=max(res[i], (latest[j]-i+1));
            }
        }
        return res;
    }
};