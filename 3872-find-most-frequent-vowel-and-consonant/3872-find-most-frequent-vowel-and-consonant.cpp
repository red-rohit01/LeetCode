class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> freq;
        for(auto &x:s) freq[x]++;

        int v=0,c=0;
        for(auto &x:freq)
        {
            if(x.first=='a' || x.first=='e' || x.first=='i' || x.first=='o' || x.first=='u') v=max(v,x.second);
            else c=max(c,x.second);
        }
        return (c+v);
    }
};