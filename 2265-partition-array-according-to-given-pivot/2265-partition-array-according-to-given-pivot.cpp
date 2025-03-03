class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>ans(n,-1e7);
        int st=0;
        int end=n-1;
        int cnt=0;
        for(int i=0;i<n;++i)
        {
            if(nums[i]<pivot)
            {
                ans[st++]=nums[i];
                cnt++;
            }
            else if(nums[i]>pivot)
            {
                ans[end--]=nums[i];
            }
            else cnt++;
        }
        for(int i=0;i<cnt;++i)
        {
            if(ans[i]==-1e7) ans[i]=pivot;
        }
        reverse(ans.begin()+cnt,ans.end());
        return ans;
    }
};