class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=k;
        sort(nums.begin(),nums.end());
        for(int i=-1;i<n;++i)
        {
            int j=i+1;
            while(j<n && nums[j]<ans) j++;

            if(j==n)  return ans;

            if(nums[j]==ans) ans+=k;
            else return ans;

            i=j-1;
        }
        return ans;
    }
};