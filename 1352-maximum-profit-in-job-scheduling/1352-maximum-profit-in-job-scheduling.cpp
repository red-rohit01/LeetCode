struct job
{
   int start;
   int end;
   int profit;
};
class Solution {
public:
    static bool cmp(job& a,job& b)
    {
        //if(a.end==b.end) return a.profit>b.profit;
        return a.end < b.end;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=profit.size();
        vector<job>rk(n);
        for(int i=0;i<n;++i)
        {
            rk[i].start=startTime[i];
            rk[i].end=endTime[i];
            rk[i].profit=profit[i];
        }

        sort(rk.begin(),rk.end(),cmp);

        vector<int>dp(n+1);    // dp[i]--> Maximum profit earned till the i'th job is completed
        dp[0]=rk[0].profit;
        for(int i=1;i<n;++i) 
        {
            int l=0,r=i-1;
            int ind=-1;
            while(l<=r)
            {
                int mid=l+(r-l)/2;
                if(rk[mid].end<=rk[i].start)
                {
                    l=mid+1;
                    ind=mid;
                }
                else r=mid-1;
            }
            if(ind==-1) dp[i]=max(dp[i-1],rk[i].profit);
            else dp[i]=max(dp[i-1], rk[i].profit+dp[ind]);
        }
        return dp[n-1];
    }
};