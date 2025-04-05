class Solution {
public:
    void solve(int i,int n,vector<int>&nums,int &ans,int temp)
    {
        if(i==n)
        {
            ans+=temp;
            return;
        }
        solve(i+1,n,nums,ans,temp^nums[i]);
        solve(i+1,n,nums,ans,temp);
    }
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        solve(0,n,nums,ans,0);
        return ans;
    }
};