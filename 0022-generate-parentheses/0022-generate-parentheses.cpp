class Solution {
public:
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