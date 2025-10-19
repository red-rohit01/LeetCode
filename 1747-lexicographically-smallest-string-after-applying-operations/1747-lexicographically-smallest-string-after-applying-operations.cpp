class Solution {
public:
    // For odd positions, we can have worst case 10 variations using "add a".
    // For even positions, we can also have worst case 10 variations when b is odd. 
    // What we do is first we rotate the even positions to the odd positions, and then use "add a". 
    // So this gives us 10 * 10 variations.
    // For each of the 10 * 10 variations, we can rotate, if b is odd, worst case each can have n variations, 
    // where n is the length of s. So finally we can have 10 * 10 * n variations.
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