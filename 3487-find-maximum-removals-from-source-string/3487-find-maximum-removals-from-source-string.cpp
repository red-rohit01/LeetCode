class Solution {
public:
    // Take, Not Take case
    int dp[3001][3001];
    int helper(int i,int j,int k,int &n,int &m,int &p,string &source,string &pattern,vector<int>& targetIndices)
    {
        if(j==m) return (p-k);   // If I reached the end, then pattern is present as the subsequence and thus all the
                                // remaining further indices can be removed carefully i.e., (p-k)
        if(i>=n) return -1e6;

        while(i<n && j<m)
        {
            if(k<p && (i==targetIndices[k])) break;

            if(source[i]==pattern[j])
            {
                i++;
                j++;
            }
            else i++;
        }            

        if(k==p)
        {
            if(j==m) return 0;
            else return -1e6;
        }            

        if(dp[i][j]!=-1) return dp[i][j];

        // remove this particular index
        int val1=1+helper(i+1,j,k+1,n,m,p,source,pattern,targetIndices);

        // Don't remove this particular index
        int val2=helper(i,j,k+1,n,m,p,source,pattern,targetIndices);

        return (dp[i][j]=max(val1,val2));
    }
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int n=source.size();
        int m=pattern.size();
        int p=targetIndices.size();

        memset(dp,-1,sizeof(dp));
        return helper(0,0,0,n,m,p,source,pattern,targetIndices);
    }
};