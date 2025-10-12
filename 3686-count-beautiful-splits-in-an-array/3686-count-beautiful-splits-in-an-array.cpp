class Solution 
{
public:
    int beautifulSplits(vector<int>& nums) 
    {
        int n=nums.size();
        if(n<3) return 0;        
        long mod=1e9+7;
        long base=50;

        vector<long long> prefixHash(n+1); // Hash for prefix [0..i)
        vector<long long> pow(n+1,1); // Store powers of base
        
        for(int i=0;i<n;++i) 
        {
            pow[i+1]=(pow[i]*base)%mod;
            prefixHash[i + 1] = (prefixHash[i] * base + nums[i]) % mod;
        }
        int count = 0;
        for(int i=1;i<n-1;++i) 
        {
            for(int j=i+1;j<n;++j) 
            {
                bool valid = false;
                // Check if nums1 is a prefix of nums2
                if (isPrefix(prefixHash, 0, i, i, j, mod, pow)) valid=true;

                // Check if nums2 is a prefix of nums3
                if (!valid && isPrefix(prefixHash, i, j, j, n, mod, pow)) valid=true;

                if (valid) count++;
            }
        }
        return count;
    }
private:
    bool isPrefix(const vector<long long>& hash, int start1, int end1, int start2, int end2, long mod, const vector<long long>& pow) 
    {
        int len1=end1-start1;
        int len2=end2-start2;
        if(len1>len2) return false;

        long long hash1 = (hash[end1] - (hash[start1] * pow[len1]) % mod + mod) % mod;
        long long hash2 = (hash[start2 + len1] - (hash[start2] * pow[len1]) % mod + mod) % mod;

        return hash1 == hash2;
    }
};