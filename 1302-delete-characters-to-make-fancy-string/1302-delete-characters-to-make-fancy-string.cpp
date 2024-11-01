class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        ans+=s[0];
        int len=s.size();
        for(int i=1;i<len;++i)
        {
            int curr_len=ans.size();
            if(curr_len>=2 && ans[curr_len-1]==ans[curr_len-2] && ans[curr_len-1]==s[i])
            {
                int j=i+1;
                while(j<len && s[j]==s[i]) j++;

                i=j-1;
            }
            else ans+=s[i];
        }
        return ans;
    }
};