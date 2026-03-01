class Solution {
public:
    // he algorithm explores a pruned recursion tree (never builds invalid sequences).
    // It generates exactly all valid combinations → optimal.
    // Total time = (# of valid combinations) × (cost to build each string)

    // Although the recursion tree looks binary, it is heavily pruned by constraints (open < n, open > close).
    // The algorithm never explores invalid states, so it generates exactly the Catalan number of valid sequences.
    // Hence time complexity is O(Cₙ · n) and not O(2^{2n}.

    // Cn= 1/(n+1) * 2nCn == (2n)!/(n+1)!xn! 
    // Total leaves = Cₙ valid sequences
    // Each sequence length = 2n
    // Building each string costs O(n)

    // so TC: O(Cn x n)
    void helper(int n,vector<string>&ans,int open,int close,string temp)
    {
        if(open==n && close==n)
        {
            ans.push_back(temp);
            return;
        }

        if(open<n) helper(n,ans,open+1,close,temp+'(');
        if(open>close) helper(n,ans,open,close+1,temp+')');
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int open=0,close=0;
        string temp="";
        helper(n,ans,open,close,temp);
        return ans;
    }
};