class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long ans=1;
        long long sum=0;
        for(auto &x:batteries)
        {
            sum+=(1LL*x);
        }
        long long l=1,h=sum/n;
        while(l<=h)
        {
            long long mid=l+(h-l)/2;
            long long extra=0;
            for(auto &x:batteries)
            {
                extra+=min(mid,1LL*x);
            }
            if(extra>=(1LL*n*mid))
            {
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        return ans;
    }
};