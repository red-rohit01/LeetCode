class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        int n=s.size();
        st.push(-1);
        int mx=0;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else 
            {
                st.pop();
                if(!st.empty()) mx=max(mx,i-st.top());
                else st.push(i);
            }
        }
        return mx;
    }
};