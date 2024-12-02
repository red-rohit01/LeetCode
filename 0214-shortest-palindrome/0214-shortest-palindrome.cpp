class Solution {
public:
    // Using KMP Algorithm, we can find the longest prefix which is part of the substring in the required palindrome.
    // Idea is we need to only append those remaining part from the given string apart from being longest palindrome
    // starting from index '0'.
    // Consider this example, s="aacecaaaz"
    // Here the longest palindromic prefix is "aacecaa". How this palindromic prefix is calculated? It's calculated using LPS
    // as it tracks the longest prefix which is also the suffix ending at index 'i'.
    // The remaining part of the string is "az".
    // To create the smallest palindrome, we reverse this remaining part and add it to the front of the original string, 
    // resulting in "zaaacecaaaz", which is a palindrome.
    vector<int>LPS(string &s)
    {
        int len=s.size();
        vector<int>ans(len);

        int comm=0;

        for(int i=1;i<len;++i)
        {
            while(comm>0 && s[i]!=s[comm]) comm=ans[comm-1];
            
            if(s[i]==s[comm]) comm++;

            ans[i]=comm;
        }
        return ans;
    }
    string shortestPalindrome(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());

        string comb=s+'#'+rev;

        vector<int>prefix=LPS(comb);

        int len=comb.size();
        int longest_palin=prefix[len-1];

        int n=s.size();

        string suff=rev.substr(0,(n-longest_palin));

        return (suff+s);
    }
};