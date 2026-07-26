class Solution {
public:
    // For e.g., if this is all the gcd values: [1,1,1,2,2,4]
    // Instead of generating these 6 values, we only want to know
    // GCD = 1 -> occurs 3 times
    // GCD = 2 -> occurs 2 times
    // GCD = 4 -> occurs 1 time
    
    // Why does subtracting multiples work?

    // Suppose we're computing : g = 6

    // Every pair divisible by 6 can have gcd

    // 6
    // 12
    // 18
    // 24
    // ...

    // No other possibilities.
    // So, pairs divisible by 6 = gcd 6 + gcd 12 + gcd 18 + ...

    // Therefore gcd exactly 6 = pairs divisible by 6 - pairs gcd 12 - pairs gcd 18 ... (inclusion-exclusion idea)

    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxVal = *max_element(nums.begin(), nums.end());

        // frequency of each value of the nums
        vector<long long> freq(maxVal+1);

        for (int x : nums) freq[x]++;

        // divCnt[g] stores the freq of numbers divisible by g
        vector<long long> divCnt(maxVal+1);

        for(int g=1;g<=maxVal;++g) 
        {
            for(int x=g;x<=maxVal;x+=g) divCnt[g]+=freq[x];
        }

        // exact[g] is the number of pairs whose gcd is exactly g
        vector<long long> exact(maxVal+1);

        for(int g=maxVal;g>=1;--g) 
        {
            exact[g]=divCnt[g]*(divCnt[g]-1)/2; //pairing of all numbers divisible by g   i.e., cntC2
        // it may be possible that two numbers are divisble by x but their gcd is not exactly x, it can be k*x so we have to remove those pairs for e.g., (4,4) their gcd is '4' not '2'
            for(int m=2*g;m<=maxVal;m+=g) exact[g]-=exact[m];
        }

        // prefix[g] => pairs with gcd <= g
        vector<long long> prefix(maxVal+1);
        for (int g=1;g<=maxVal;++g) prefix[g]=prefix[g-1]+exact[g];

        vector<int> ans;
        for (long long q : queries) 
        {
            // first gcd whose prefix > q
            int g=lower_bound(prefix.begin() + 1, prefix.end(), q+1) - prefix.begin();
            ans.push_back(g);
        }
        return ans;
    }
};