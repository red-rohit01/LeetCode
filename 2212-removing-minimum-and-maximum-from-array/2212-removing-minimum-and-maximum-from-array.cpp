class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        int mn=nums[0];
        int mn_ind=0;
        int mx=nums[0];
        int mx_ind=0;
        for(int i=1;i<n;++i)
        {
            if(nums[i]<mn)
            {
                mn=nums[i];
                mn_ind=i;
            }
            if(nums[i]>mx)
            {
                mx=nums[i];
                mx_ind=i;
            }
        }

        int ans=n;
        int val1=max(mn_ind+1,mx_ind+1);
        ans=min(ans,val1);
        int val2=max((n-mn_ind),(n-mx_ind));
        ans=min(ans,val2);

        int val3=mn_ind+1+(n-mx_ind);
        ans=min(ans,val3);
        int val4=mx_ind+1+(n-mn_ind);
        ans=min(ans,val4);
        return ans;
    }
};