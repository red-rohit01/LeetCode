class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int l=-1, h=n;
        while(l+1<h)
        {
            int mid=l+(h-l)/2;
            if(nums[mid]<0) l=mid;
            else h=mid;
        }

        int last_neg=l;

        l=-1,h=n;
        while(l+1<h)
        {
            int mid=l+(h-l)/2;
            if(nums[mid]<=0) l=mid;
            else h=mid;
        }

        int first_pos=h;

        int val1=last_neg+1;
        int val2=(n-first_pos);
        return max(val1,val2);
    }
};