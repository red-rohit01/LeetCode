class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n=time.size();
        int ans=0;
        vector<int>freq(60);
        for(int i=0;i<n;++i)
        {
            int curr=(time[i]%60);
            int req=(60-curr)%60;

            ans+=freq[req];
            freq[curr]++;
        }
        return ans;
    }
};