class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n=text.size();
        unordered_map<char,int>mp;
        for(auto &x:text)
        {
            if(x=='b' || x=='a' || x=='l' || x=='o' || x=='n') mp[x]++;
        }

        if(mp.size()<5) return 0;

        int mx=n;
        for(auto &x:mp)
        {
            int curr=x.second;
            if(x.first=='l' || x.first=='o') curr/=2;

            mx=min(mx,curr);
        }
        return mx;
    }
};