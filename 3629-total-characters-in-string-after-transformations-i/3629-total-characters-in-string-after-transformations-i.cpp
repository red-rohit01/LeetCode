class Solution {
public:
    // The idea is simple. Check for each of the freq and then update it accordingly
    int lengthAfterTransformations(string s, int t) {
        const int mod=1e9+7;
        vector<long long>freq(26);

        for (char &x:s) freq[x-'a']++;

        for (int j=0;j<t;++j) 
        {
            vector<long long>tmp(26);
            for (int i = 0; i < 26; i++) 
            {
                if (i==25) 
                {
                    tmp[0]=(tmp[0]%mod + freq[i]%mod)%mod;
                    tmp[1]=(tmp[1]%mod + freq[i]%mod)%mod;
                } 
                else tmp[i+1]=(tmp[i+1]%mod + freq[i]%mod)%mod;
            }
            freq=tmp;
        }

        long long len=0;
        for (long long x:freq) len=(len%mod+x%mod)%mod;

        return len;
    }
};