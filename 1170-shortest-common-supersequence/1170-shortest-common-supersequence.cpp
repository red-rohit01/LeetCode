class Solution {
public:
    string shortestCommonSupersequence(string& A, string& B) {
        string res="";
        int n = A.size(), m = B.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if (A[i]==B[j]) dp[i+1][j+1]=dp[i][j]+1;

                else dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
        int i=n,j=m;
        while(i>0 && j>0)
        {
            if(A[i-1]==B[j-1])
            {
                res.push_back(A[i-1]);
                i--;
                j--;
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1])
                {
                    res.push_back(A[i-1]);
                    i--;
                } 
                else
                {
                    res.push_back(B[j-1]);
                    j--;
                }
            }
        }

        while(i>0) 
        {
            res.push_back(A[i-1]);
            i--;
        }
        while(j>0) 
        {
            res.push_back(B[j-1]);
            j--;
            
        }
        reverse(res.begin(),res.end()); 
        return res;
    }
};