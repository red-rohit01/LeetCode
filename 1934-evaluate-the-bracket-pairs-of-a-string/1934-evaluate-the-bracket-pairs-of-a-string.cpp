class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n=s.size();
        string ans;
        map<string,string>keyValue;
        for(auto &x:knowledge)
        {
            keyValue[x[0]]=x[1];
        }

        for(int i=0;i<n;++i)
        {
            if(s[i]=='(')
            {
                string curr;
                int j=i+1;
                while(j<n && s[j]!=')') curr+=s[j++];

                if(keyValue.find(curr)!=keyValue.end()) ans+=keyValue[curr];
                else ans+="?";

                i=j;
            }
            else ans+=s[i];
        }
        return ans;
    }
};