class Solution {
public:
    int helper(int i,int j,int &n,int &m,string &s,string &p,auto &dp)
    {
        if(i==n)
        {
            for(int k=j;k<m;++k) 
            {
                if(p[k]!='*') return false;
            }
            return true;
        }

        if(j==m) return false;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==p[j]) return dp[i][j]=helper(i+1,j+1,n,m,s,p,dp);

        if(p[j]=='?') return dp[i][j]=helper(i+1,j+1,n,m,s,p,dp);

        bool flag=false;
        if(p[j]=='*')
        {
            for(int l=i;l<n;++l)
            {
                flag|=helper(l,j+1,n,m,s,p,dp);             // Replacing '*' with empty sequence
                flag|=helper(l+1,j+1,n,m,s,p,dp); 
            }
        }
        return dp[i][j]=flag;
    }
    bool isMatch(string s, string p) {
       int n=s.size();
       int m=p.size();
       vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

       return helper(0,0,n,m,s,p,dp); 
    }
};