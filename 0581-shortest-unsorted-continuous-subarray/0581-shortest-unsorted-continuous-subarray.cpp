class Solution {
public:
    // The idea is simple, find out the farthest number which is smaller than the largest number traversing from left side. 
    // and the earliest number which is greater than the minm number encountered till now traversing from the right side.
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int beg=-1;
        int end=-2;    // We have smartly initialized with '-2' so, that if it's sorted already then there is no need to have additional if check at the end, we can straight away return (end-beg+1)
        int mx=nums[0],mn=nums[n-1];

        for(int i=1;i<n;++i)
        {
            mx=max(mx,nums[i]);
            mn=min(mn,nums[n-i-1]);

            if(nums[i]<mx) end=i;

            if(nums[n-i-1]>mn) beg=n-i-1;

            // cout<<mx<<" "<<mn<<" "<<beg<<" "<<end<<"\n";
        }

        return (end-beg+1);
    }
};