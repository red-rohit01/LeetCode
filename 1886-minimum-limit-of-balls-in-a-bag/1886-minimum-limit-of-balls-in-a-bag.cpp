class Solution {
public:
    bool predicate(vector<int>&nums,int mid,int &maxOperations)
    {
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;++i)
        {
            if(nums[i]>mid)
            {
                cnt+=(nums[i]+mid-1)/mid;
                cnt--;
            }

            if(cnt>maxOperations) return false;
        }
        return (cnt<=maxOperations);
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=1,h=nums[n-1];
        int ans=h;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(predicate(nums,mid,maxOperations))
            {
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};