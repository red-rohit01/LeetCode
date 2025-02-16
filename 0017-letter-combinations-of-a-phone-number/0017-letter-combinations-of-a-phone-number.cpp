class Solution {
public:
    vector<string>mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void helper(string digits, int ind, vector<string>&ans,string &curr)
    {
        if(ind==digits.size())
        {
            ans.push_back(curr);
            return;
        }
        int val=digits[ind]-'0';
        for(auto &x:mp[val])
        {
            curr.push_back(x);
            helper(digits,ind+1,ans,curr);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        int n=digits.size();
        if(n==0) return ans;
        string curr="";
        helper(digits,0,ans,curr);
        return ans;
    }
};