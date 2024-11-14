class Solution {
public:
    bool check(int mid,int n,vector<int> quantities)
    {
        int len=quantities.size();
        int j=len-1;
        int cnt=0;
        for(;j>=0;--j)
        {
            int curr=(quantities[j]+mid-1)/mid;
            cnt+=curr;
        }
        return (cnt<=n);
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l=1;
        sort(quantities.begin(),quantities.end());
        int len=quantities.size();
        int h=quantities[len-1];

        int ans=h;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(check(mid,n,quantities))
            {
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};