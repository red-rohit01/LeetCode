
class Solution {
public:
    // Can be implemented with DP also,
    // DP[i]--> represents whether there can be a split at index 'i' or not.
    // TC: O(n^2)
    bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string>dict(wordDict.begin(),wordDict.end());
    // queue<int> q;
    // unordered_set<int> visited;
    
    // q.push(0);
    // while(q.size()>0)
    // {
    //     int start = q.front();
    //     q.pop();
    //     if(visited.find(start) == visited.end())
    //     {
    //         visited.insert(start);
    //         for(int j=start; j<s.size(); j++)
    //         {
    //             string word(s, start, j-start+1);
    //             if(dict.find(word) != dict.end())
    //             {
    //                 q.push(j+1);
    //                 if(j+1 == s.size()) return true;
    //             }
    //         }
    //     }
    // }
    // return false;
        int n=s.size();
        vector<int>dp(n+1);
        dp[0]=1;
        for(int i=1;i<=n;++i)
        {
            for(int j=i;j>=1;--j)
            {
                string word(s,j-1,(i-j+1));      // (J-1) because it's 1 based indexing
                if(dict.find(word)!=dict.end() && dp[j-1]==1)
                {
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[n];
    }
};