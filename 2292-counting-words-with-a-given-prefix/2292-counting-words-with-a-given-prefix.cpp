class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=words.size();
        int ans=0;
        int len=pref.size();
        for(int i=0;i<n;++i)
        {
            string curr=words[i];
            string str=curr.substr(0,len);
            if(str==pref) ans++;
        }
        return ans;
    }
};