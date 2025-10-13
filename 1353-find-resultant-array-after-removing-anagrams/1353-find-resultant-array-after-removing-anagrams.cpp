class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n=words.size();
        stack<string>st;
        for(int i=0;i<n;++i)
        {
            if(st.empty()) st.push(words[i]);
            else 
            {
                string topString=st.top();
                sort(topString.begin(),topString.end());
                string curr=words[i];
                sort(curr.begin(),curr.end());
                if(curr!=topString) st.push(words[i]);
            }
        }
        vector<string>ans;
        while(!st.empty()) 
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};