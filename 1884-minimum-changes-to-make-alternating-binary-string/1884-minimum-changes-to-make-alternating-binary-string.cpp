class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int prev=0;
        int ans=0;
        
        for(int i=0;i<n;++i)
        {
            if((s[i]-'0')!=prev) ans++;
            
            prev=1-prev;
        }
        return min(ans,(n-ans));
    }
};