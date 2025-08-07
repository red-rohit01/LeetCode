class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int ans=0;
        int n=fruits.size();
        if(n==2)
        {
            ans+=fruits[0][0]+fruits[0][1]+fruits[1][0]+fruits[1][1];
            return ans;
        }
        if(n==3)
        {
            ans+=fruits[0][0]+fruits[0][2]+fruits[1][1]+fruits[1][2]+fruits[2][0]+fruits[2][1]+fruits[2][2];
            return ans;
        }

        //First Child {0,0}  // To reach the cell {n-1,n-1} It can only traverse in the diagonal direction.
        for(int i=0;i<n;++i)
        {
            ans+=fruits[i][i];
        }
        fruits[n-1][n-1]=0;

        vector<vector<int>>dp(n,vector<int>(n));
        dp[0][n-1]=fruits[0][n-1];

        for(int i=0;i<n;++i)
        {
            for(int j=(n-i-1);j<n;++j)    // Here 'j' is initialized with (n-i-1) as we can allow only this much deviation on 'j' value so that It's ensured to reach (n-1,n-1)
            {
                if((i+1)<n && (i+1)<j) dp[i+1][j]=max(dp[i+1][j], dp[i][j]+fruits[i+1][j]);

                if((i+1)<n && (j+1)<n && (i+1)<(j+1)) dp[i+1][j+1]=max(dp[i+1][j+1], dp[i][j]+fruits[i+1][j+1]);

                if((i+1)<n && (i+1)<(j-1)) dp[i+1][j-1]=max(dp[i+1][j-1], dp[i][j]+fruits[i+1][j-1]);
            }
        }

        ans+=dp[n-2][n-1];     // fruits at position {n-1,n-1} was already consumed by the boy moving diagonal

        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j) dp[i][j]=0;
        }

        dp[n-1][0]=fruits[n-1][0];

        for(int j=0;j<n;++j)
        {
            for(int i=(n-j-1);i<n;++i)
            {
                if((j+1)<n && (j+1)<i) dp[i][j+1]=max(dp[i][j+1], dp[i][j]+fruits[i][j+1]);

                if((i+1)<n && (j+1)<n && (i+1)>(j+1)) dp[i+1][j+1]=max(dp[i+1][j+1], dp[i][j]+fruits[i+1][j+1]);

                if((i-1)>=0 &&  (i-1)>(j+1)) dp[i-1][j+1]=max(dp[i-1][j+1], dp[i][j]+fruits[i-1][j+1]);
            }
        }

        ans+=dp[n-1][n-2];
        return ans;
    }
};