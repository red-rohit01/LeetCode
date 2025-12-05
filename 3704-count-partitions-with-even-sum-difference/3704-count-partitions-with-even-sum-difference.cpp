class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total=0;
        int n=nums.size();
        for(auto &x: nums) total+=x;

        if(total%2==0) return (n-1);
        else return 0;

        // int curr=0;
        // int ans=0;
        // for(int i=0;i<n-1;++i)
        // {
        //     curr+=nums[i];
        //     if((total-2*curr)%2==0) ans++;
        // }
        // return ans;
    }
};