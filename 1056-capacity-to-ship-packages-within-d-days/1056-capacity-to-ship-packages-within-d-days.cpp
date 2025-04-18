class Solution {
public:
    bool check(vector<int>& weights, int days, int capacity)
    {
        int requiredDays=1;
        int currWeight=0;
        for(auto& i: weights)
        {
            if(currWeight + i > capacity)
            {
                requiredDays++;
                currWeight=0;
            }
            currWeight+=i;
        }
        return (requiredDays<=days);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=0;
        int h=0;
        for(auto &x:weights)
        {
            l=max(l,x);
            h+=x;
        }

        int ans=h;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(check(weights,days,mid))
            {
                ans=mid;
                h=mid-1;
            } 
            else l=mid+1;
        }
        return ans;
    }
};