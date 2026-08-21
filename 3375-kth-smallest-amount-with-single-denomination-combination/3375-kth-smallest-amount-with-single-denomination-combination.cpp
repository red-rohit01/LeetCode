class Solution {
    long long gcd(long long a, long long b) {
        while (b) 
        {
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    // We use:
    // LCM(a, b) = a / GCD(a, b) * b
    //
    // Dividing first helps reduce the chance of overflow.
    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n=coins.size();

        // Each subset contributes one term to the
        // inclusion-exclusion calculation.
        //
        // pair.first  = LCM of the coins in this subset
        // pair.second = +1 if subset size is odd
        //                -1 if subset size is even
        //
        // Why LCM? An amount is divisible by every coin in a subset exactly when it is divisible by their LCM.
        vector<pair<long long, int>> subsets;

        // There are at most 2^15 - 1 non-empty subsets.
        for(int mask=1;mask<(1<<n);++mask) 
        {
            long long curLcm = 1;
            int bits = 0;

            for (int i = 0; i < n; ++i) 
            {
                // Check whether coin i belongs to this subset.
                if (mask & (1 << i)) 
                {
                    ++bits;

                    // LCM of all coins selected in this subset.
                    curLcm = lcm(curLcm, coins[i]);
                }
            }

            // Inclusion-exclusion:
            
            // Odd number of selected sets  -> add
            // Even number of selected sets -> subtract
            
            // Example for coins [2, 5]:
            
            // multiples of 2 + multiples of 5 - multiples of LCM(2,5)
            
            // This prevents numbers such as 10 from being counted twice.
            int sign = (bits & 1) ? 1 : -1;

            subsets.push_back({curLcm, sign});
        }

        // Returns how many DISTINCT positive amounts <= x
        // can be made using at least one of the coins.
        //
        // For one coin c:
        // number of multiples of c <= x = x / c
        //
        // But multiples can overlap between different coins,
        // so we use inclusion-exclusion over all subsets.
        auto count = [&](long long x) {
            long long total = 0;

            for (auto [v, sign] : subsets) {
                // If the LCM itself is greater than x,
                // there cannot be any positive multiple of it <= x.
                if (v > x)
                    continue;

                // Number of multiples of v <= x.
                total += sign * (x / v);
            }

            return total;
        };

        // The smallest possible amount is at least 1.
        long long left = 1;

        // Upper bound:
        // Let m be the smallest coin.
        //
        // The multiples of m are:
        // m, 2m, 3m, ..., km
        //
        // Therefore the kth valid amount can never be
        // greater than k * m.
        long long right=1LL*k*(*min_element(coins.begin(), coins.end()));

        // Binary search for the smallest x such that
        // at least k valid amounts are <= x.
        while (left < right) 
        {
            long long mid = left + (right - left) / 2;

            // If there are already at least k valid amounts
            // up to mid, the answer is <= mid.
            if (count(mid)>=k) right=mid;
            
            // Otherwise, the kth amount must be larger.
            else left=mid+1;
        }

        return left;
    }
};