class Solution {
public:
    string sortVowels(string s) {
        int n=s.size();
        string ans="";
        map<int,int>rk;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            {
                rk[s[i]]++;
            }
        }
        
        for(int i=0;i<n;++i)
        {
            if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            {
               auto it=rk.begin();
                char c=(char)(it->first);
                ans+=c;
                it->second--;
                if(it->second==0) rk.erase(it);
                
            }
            else ans+=s[i];
        }
        return ans;
    }
};