class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        if(n<3) return n;
        vector<int>freq(26);
        for(int i=0;i<n;++i)
        {
            int ind=s[i]-'a';
            freq[ind]++;
            if(freq[ind]==3) freq[ind]-=2;
        }

        int ans=0;
        for(auto &x:freq) ans+=x;
        return ans;
    }
};