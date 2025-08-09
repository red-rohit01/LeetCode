class Solution {
public:
    /*string lcs(string s,string t)            // This code is for largest palindromic subsequence not substring
    {
        int n=s.size();
        int m=n;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
        string ans="";
        int i=m,j=n;
         while(i>0 && j>0)
         {
             if(s[i-1]==t[j-1])
             {
                 ans.push_back(s[i-1]);
                 i--;
                 j--;
             }
             else
             {
                 if(dp[i][j-1]>dp[i-1][j])
                 {
                     j--;
                 }
                 else
                 {
                     i--;
                 }
             }
         }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string longestPalindrome(string s) {
        string temp=s;
        reverse(temp.begin(),temp.end());
        return lcs(s,temp);
    } */
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n<=1) return s;
        vector<vector<bool>>dp(n+1,vector<bool>(n+1));
        int mxlen=1;     // maximum palindromic length 
        int mx_st=0;     // Keeps track of the starting index of the max length possible.
        for(int i=0;i<n;++i)
        {
            dp[i][i]=true;
            if((i+1)<n && s[i]==s[i+1]) 
            {
                dp[i][i+1]=1;
                mxlen=2;
                mx_st=i;
            }
        }

        for(int i=n-2;i>=0;--i)
        {
            for(int len=2;len<=(n-i);++len)   // length under consideration starting from index 'i'
            {
                int j=i+len-1;
                if(s[i]==s[j] && dp[i+1][j-1]==1) dp[i][j]=1;

                if(dp[i][j] && mxlen<len)
                {
                    mxlen=len;
                    mx_st=i;
                }
            }
        }
        return s.substr(mx_st,mxlen);
    }
};