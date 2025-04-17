class Solution {
    public:
        // TC:O(n*sqrt(k))
        int countPairs(vector<int>& nums, int k) {
            int ans=0;
            unordered_map<int, vector<int>>mpp;
            for (int i=0;i<nums.size();++i) mpp[nums[i]].push_back(i);

            vector<int>divisors;
            for (int d=1;(d*d)<=k;++d) 
            {
                if((k%d)==0) 
                {
                    divisors.push_back(d);
                    if (d!=k/d) divisors.push_back(k / d);
                }
            }
            for (auto& [key,indices]:mpp) 
            {
                unordered_map<int, int> mpp2;
                for (int &i:indices) 
                {
                    int gcdd=__gcd(i, k);
                    int need = k / gcdd;
                    // adding all previous j with j % need == 0
                    ans+=mpp2[need]; 
                    for (int &d:divisors) 
                    {
                        if(i%d==0) mpp2[d]++;
                    }
                }
            }
            return ans;
        }
    };