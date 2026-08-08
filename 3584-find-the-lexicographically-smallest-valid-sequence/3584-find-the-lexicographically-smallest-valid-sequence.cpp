class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();

        vector<int>dp(n+1);      //dp[i]-->denotes the length of suffix in word2 which is present as a subsequence in  
        int j=m-1;               // 'word1' for substring in word1 starting from index 'i'.

        for(int i=n-1;i>=0;--i)
        {
            dp[i]=dp[i+1];
            if(j>=0 && word1[i]==word2[j])
            {
                dp[i]++;
                j--;
            }
        }
       
        j=0;
        bool flag=true;
        vector<int>ans;
        for(int i=0;i<n && j<m;++i)
        {
            if(word1[i]==word2[j])
            {
                ans.push_back(i);
                j++;
            }
            else if(dp[i+1]>=(m-j-1) && flag==true) //remaining capacity from first string>=remaining characters to match in second string
            {
                ans.push_back(i);
                flag=false;
                j++;
            }
        }
        if(ans.size()==m) return ans;
        return {};
    }
};