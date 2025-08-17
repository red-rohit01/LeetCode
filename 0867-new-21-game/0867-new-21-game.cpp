class Solution {
public:
    double new21Game(int n, int k, int maxPts) {

        if (k== 0 || n >= k+maxPts) return 1.0;            // Maximum points that I can get is (k-1+maxPts)

        vector<double>dp(n+1);              //dp[i]=probability of having exactly i points
        dp[0]=1.0;
        double Wsum = 1.0;              // It's storing the summation for the window of 'maxPts' 
        double res = 0.0;              // The actual solution would be summation from 'k' till 'n'

        /* This would be the original solution but would give TLE:
        for (int i = 1; i <= maxPoint; i++) {
            for (int w = 1; w <= W; w++) {
                if (i - w >= 0 && i - w < K)
                    probability[i] += probability[i - w] * 1 / W;
            }
        } 
        and then summmation from K till N would be our res
        */
        for(int i=1;i<=n;++i) 
        {
            dp[i]=Wsum/maxPts;
            if (i<k) Wsum+=dp[i]; 
            else res += dp[i];                              // Now i>=k so adding to our res.

            if((i-maxPts)>=0) Wsum-=dp[i-maxPts];           // Removing the values out of window of size equals 'maxPts'
        }
        return res;
    }
};