class Solution {
public:
    int dp[1001][1001];
    int solve(int i ,int j,string& s1, string& s2)
    {
        if(i==s1.size()) return s2.size()-j;
        if(j==s2.size()) return s1.size()-i;
           
        if(dp[i][j]!=-1) return dp[i][j];
       
        if(s1[i] == s2[j]) return dp[i][j]=solve(i+1, j+1, s1, s2);
        else 
        {
            int insert_op=1+solve(i, j + 1, s1, s2);
            int delete_op=1+solve(i + 1, j, s1, s2);
            int replace_op=1+solve(i + 1, j + 1, s1, s2);
            return  dp[i][j]=min({insert_op, delete_op, replace_op});
        }
    }
    int minDistance(string word1, string word2) {
    // int m=word1.length();
    // int n=word2.length();
    // // dp[i][j] := min # of operations to convert word1[0..i) to word2[0..j)
    // vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // for (int i = 1; i <= m; ++i)
    //   dp[i][0] = i;

    // for (int j = 1; j <= n; ++j)
    //   dp[0][j] = j;

    // for (int i = 1; i <= m; ++i)
    // {
    //     for (int j = 1; j <= n; ++j)
    //     if (word1[i - 1] == word2[j - 1])
    //       dp[i][j] = dp[i - 1][j - 1];
    //     else
    //       dp[i][j] =1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
    //                          //replace     //delete from word1        //insert in word1
    // }
    // return dp[m][n];

    memset(dp ,-1,sizeof(dp));
    return solve(0,0,word1,word2);
    }
};