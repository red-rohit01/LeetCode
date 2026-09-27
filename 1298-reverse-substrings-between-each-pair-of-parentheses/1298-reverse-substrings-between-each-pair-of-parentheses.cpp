class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        string ans="";
        vector<int>open,pair(n);
        for(int i=0;i<n;++i)
        {
            if(s[i]=='(') open.push_back(i);
            else if(s[i]==')')
            {
                int last=open.back();
                open.pop_back();

                pair[i]=last;                           // Wormhole based solution
                pair[last]=i;
            }
        }

        for(int i=0,d=1;i<n;i+=d)
        {
            if(s[i]=='(' || s[i]==')')
            {
                i=pair[i];
                d=-d;
            }
            else ans+=s[i];
        }
        return ans;
    }
};