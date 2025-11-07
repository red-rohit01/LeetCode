class Solution {
public:
    bool check(vector<long long> mx,long long mid,long long r,long long k)
    {
        int n=mx.size();
        vector<long long>roda(n);
        int j=2*r +1;                    // placing a power station at (i+r)th city will give power frok i to (i+ 2*r)th city
        long long sm=0;
        for(int i=0;i<n;++i)
        {
            sm+=roda[i];
            mx[i]+=sm;
            long long diff=mid-mx[i];
            if(diff>0)
            {
                if(diff>k) return false;
                k-=diff;
                sm+=diff;
                if((i+j)<n) roda[i+j]-=diff;
            }
        }
        return k>=0;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        int n=stations.size();
        if(n==1) return stations[0]+k;
        
        vector<long long>mx(n),pre(n);

        pre[0]=stations[0]*1LL;
        for(int i=1;i<n;++i) pre[i]=stations[i]+pre[i-1];
        
        for(int i=0;i<n;++i)
        {
            mx[i]=1LL*(stations[i]);
            int ind=min((i+r),n-1);
            mx[i]+=1LL*(pre[ind]-pre[i]);

            if(i==0) continue;

            mx[i]+=1LL*pre[i-1];
            if((i-r-1)>=0) mx[i]-=1LL*(pre[i-r-1]);
        }

        long long ans=0;
        long long l=0,h=1e14;
        while(l<=h)
        {
            long long mid=l + (h-l)/2;
            if(check(mx,mid,1LL*r,1LL*k))
            {
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        return ans;
    }
};