class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.size();
        int mod=1e9+7;

        vector<int>countEndWith(26);     // Number of distinct subsequences currently ending with character 'i'
        int sum=0;                       // number of distinct non-empty subsequences seen so far.

        for(int i=0;i<n;++i)
        {
            int idx=s[i]-'a';

            // Create new subsequences and remove duplicates
            int cur=(1+sum-countEndWith[idx]+mod)%mod; // Every subsequence that was already ending with c will be recreated when we append the new 'idx'.so, subtracted.

            sum=(sum+cur)%mod;

            // Update subsequences ending with this character
            countEndWith[idx]=(countEndWith[idx]+cur)%mod;
        }
        return sum;
    }
};