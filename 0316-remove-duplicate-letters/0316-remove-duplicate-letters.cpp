class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        map<char,int>freq;
        for(int i=0;i<n;++i) freq[s[i]]++;

        stack<char>st;
        vector<bool>vis(26);
        for(int i=0;i<n;++i)
        {
            if(vis[s[i]-'a']==1)
            {
                freq[s[i]]--;
                continue;
            }

            while(st.size()>0 && s[i]<=st.top() && freq[st.top()]>=1)  // Here freq check >=1 because we know there will be atleast one 'st.top()' value would be present later on to take.
            {
                vis[st.top()-'a']=0;
                st.pop();
            }

            st.push(s[i]);
            vis[s[i]-'a']=1;
            freq[s[i]]--;
        }
        string ans="";
        while(!st.empty()) 
        {
            char c=st.top();
            st.pop();
            ans+=c;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};