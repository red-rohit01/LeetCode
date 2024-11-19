class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        long long sm=0,ans=0;
        set<int>s;
        while(j<n)
        {
            sm+=nums[j];
            bool flag=false;
            if(s.find(nums[j])==s.end())
            {
                s.insert(nums[j]);
                flag=true;
            }
            else if(!flag)
            {
                while(nums[i]!=nums[j])
                {
                    sm-=nums[i];
                    s.erase(nums[i]);
                    i++;
                }
                 sm-=nums[i];
                 s.erase(nums[i]);
                 i++;
                s.insert(nums[j]);
            }
            
            if(j-i+1 <k)
            {
                j++;
            }
            else if(j-i+1 ==k)
            {
                ans=max(ans,sm);
                j++;
                sm-=nums[i];
                s.erase(nums[i]);
                i++;
            }
        }
        return ans;
    }
};