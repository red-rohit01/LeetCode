class Solution {
public:
    char mn_char(map<char,int>&freq)
    {
        for(auto &x:freq)
        {
            if(x.second>0) return x.first;
        }
        return 'a';
    }
    string robotWithString(string s) {
        map<char,int>freq;
        for(auto &x:s) freq[x]++;

        stack<int>t;
        string ans="";
        for(auto &i:s)
        {
            t.push(i);
            freq[i]--;
            while(!t.empty() && t.top()<=mn_char(freq))
            {
                ans+=t.top();
                t.pop();
            }
        }
        while(!t.empty())
        {
            ans+=t.top();
            t.pop();
        }
        return ans;
    }
};