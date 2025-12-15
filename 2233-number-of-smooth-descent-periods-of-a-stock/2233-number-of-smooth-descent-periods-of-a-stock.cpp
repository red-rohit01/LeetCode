class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        int curr=1;
        long long ans=1;
        for(int i=1;i<n;++i)
        {
            if(prices[i]==(prices[i-1]-1)) curr++;
            else curr=1;

            ans+=curr;
        }
        return ans;
    }
};