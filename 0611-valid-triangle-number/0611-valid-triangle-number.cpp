class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int ans=0;
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                int side=(nums[j]-nums[i]);
                auto it=upper_bound(nums.begin(),nums.begin()+i,side)-nums.begin();
                int number_of_sides=(i-it);
                ans+=number_of_sides;
            }
            
        }
        return ans;
    }
};