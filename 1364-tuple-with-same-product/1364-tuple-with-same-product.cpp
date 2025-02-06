class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        sort(nums.begin(),nums.end());
        map<int,int>freq;
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                int prod=nums[i]*nums[j];
                freq[prod]++;
            }
        }

        for(auto &x:freq)
        {
            int curr=x.second;
            int pairs=(curr*(curr-1))/2;

            ans+=pairs*8;
        }
        return ans;
    }
};