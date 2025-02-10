class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        string rk="";
        int n=s.size();
        for(int i=0;i<n;++i)
        {
            if(s[i]>='a' && s[i]<='z') st.push(s[i]);
            
            else st.pop();
        }
        while(st.size())
        {
            rk.push_back(st.top());
            st.pop();
        }
        reverse(rk.begin(),rk.end());
        return rk;
    }
};