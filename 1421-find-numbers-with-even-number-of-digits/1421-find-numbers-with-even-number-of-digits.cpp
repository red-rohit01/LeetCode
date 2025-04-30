class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;++i)
        {
            int curr=nums[i];
            int digits=0;
            while(curr)
            {
                digits++;
                curr/=10;
            }

            if(digits%2==0) ans++;
        }
        return ans;
    }
};