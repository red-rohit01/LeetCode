class Solution {
public:
    unordered_set<string>vis;
    string ans;
    string rotate(string s, int &b)
    {
        reverse(s.begin(),s.end());
        reverse(s.begin(),s.begin()+b);
        reverse(s.begin()+b,s.end());
        return s;
    }
    string add(string s, int &a)
    {
        int n=s.size();
        for(int i=1;i<n;i+=2)
        {
            char &c=s[i];
            c='0'+(c-'0'+a)%10;
        }
        return s;
    }
    void dfs(string s, int &a, int &b)
    {
        if(vis.find(s)!=vis.end()) return;

        ans=min(ans,s);
        vis.insert(s);
        dfs(rotate(s,b),a,b);
        dfs(add(s,a),a,b);
    }
    string findLexSmallestString(string s, int a, int b) {
        ans=s;
        dfs(s,a,b);
        return ans;
    }
};