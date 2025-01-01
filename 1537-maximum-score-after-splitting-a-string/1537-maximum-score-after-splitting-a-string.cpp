class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int cnt_1=0;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='1') cnt_1++;
        }
        int ans=0;
        int cnt_0=0;
        for(int i=0;i< n-1;++i)
        {
            if(s[i]=='0') cnt_0++;
            int rem=(cnt_1-(i+1-cnt_0));
            int curr=rem+cnt_0;
            ans=max(ans,curr);
        }
        return ans;
    }
};