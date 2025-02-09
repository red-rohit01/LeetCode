class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n=nums.size();
        map<int,int>rk;
        for(long long i=0;i<n;i++)
        {
            rk[(nums[i]-i)]++;
        }
        long long cnt=0;
        for(auto m:rk)
        {
            long long l=(long long)m.second;
            cnt+=((l-1)*l)/2;
        }
        return (long long)(n*(n-1))/2 -cnt;
    }
};