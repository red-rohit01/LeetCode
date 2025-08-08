class Solution {
public:
    bool check(int mid,auto &order,string s,int &k)
    {
        for(int i=0;i<=mid;++i) s[order[i]]='*';

        long non_star=0;
        long cnt=0L;
        long len=s.size();
        for(long i=0;i<len;++i)
        {
            if(s[i]=='*')
            {
                long curr_sub=(cnt*(cnt+1))/2;
                non_star+=curr_sub;
                cnt=0L;
            }
            else cnt++;
        }
        non_star+=(cnt*(cnt+1))/2;
        long total=len*(len+1)/2;
        return (total-non_star)>=1L*k;
    }
    int minTime(string s, vector<int>& order, int k) {
        int n=order.size();
        int l=0,h=n-1;
        int ans=n+1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(check(mid,order,s,k))
            {
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        if(ans==n+1) return -1;
        return ans;
    }
};