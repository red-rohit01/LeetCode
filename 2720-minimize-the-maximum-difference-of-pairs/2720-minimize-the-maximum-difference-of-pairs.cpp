class Solution {
public:
    int minimizeMax(vector<int>& rk, int p) {
        int n=rk.size();
        sort(rk.begin(),rk.end());
    
        int mx=rk[n-1]-rk[0];
        int l=0,h=mx;
        
        int ans=mx;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            int cnt=0;
            for(int i=0;i<n-1;++i)
            {
                int diff=(rk[i+1]-rk[i]);
                if(diff<=mid)
                {
                    cnt++;
                    i++;
                }
            }
            if(cnt>=p)
            {
                ans=mid;
                h=mid-1;
            }
            else l=mid+1; 
        }
        return ans;
    }
};