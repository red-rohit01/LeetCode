class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l=strs.size();
        vector<vector<vector<int>>>dp(l+1,vector<vector<int>>(m+1,vector<int>(n+1)));
        
        for(int i=1;i<=l;++i) 
        {
            int ones=0,zeros=0;
            for(int j=0;j<strs[i-1].size();++j) 
            {
                if(strs[i-1][j]=='1') ones++;
                else zeros++;
            }
            
            for(int j=0;j<=m;++j) 
            {
                for(int k=0;k<=n;++k) 
                {
                    if(j>=zeros && k>=ones) dp[i][j][k]=max(dp[i-1][j][k],1+dp[i-1][j-zeros][k-ones]);
                    
                    else dp[i][j][k]=dp[i-1][j][k];
                }
            }
        } 
        return dp[l][m][n];
    }
}; 