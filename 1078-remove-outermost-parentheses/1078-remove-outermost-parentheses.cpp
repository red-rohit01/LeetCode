class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int sum=0,lastIndex=0;
        int n=s.size();
        for(int i=0;i<n;++i) 
        {
            if(s[i] == '(') sum++;
            else if(s[i] == ')') sum--;
            
            if(sum==0) 
            {
                ans+=s.substr(lastIndex+1, i-lastIndex-1);
                lastIndex = i+1;
            }
        }
        return ans;
    }
};