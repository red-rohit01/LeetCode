class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int ans=0;

        for(int i=0;i<n;++i)
        {
            int l=0,h=m-1;
            int ind=i;
            while(l<=h)
            {
                int mid=l+(h-l)/2;
                if(nums2[mid]>=nums1[i])
                {
                    ind=mid;
                    l=mid+1;
                }
                else h=mid-1;
            }
            ans=max(ans,ind-i);
        }
        return ans;
    }
};