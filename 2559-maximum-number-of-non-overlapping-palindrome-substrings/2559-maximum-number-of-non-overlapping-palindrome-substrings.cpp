class Solution {
public:
    int maxPalindromes(string s, int k) {
    int n=s.size();
    int ans = 0;

    // 'end' stores the ending index of the last selected palindrome.
    // A new palindrome must start after this index to avoid overlap.
    int end=-1;

    for (int i = 0; i < n; ++i) 
    {
        // Every palindrome has either:
        // 1. An even-length center between i-1 and i
        // 2. An odd-length center at i
        // We check both types.
        for (int type=0;type<2;++type) 
        {
            int l=(type==0)?i-1:i;
            int r=i;

            // Expand outward while the substring remains a palindrome.
            while (l >= 0 && r < n && s[l] == s[r]) 
            {
                // If the palindrome is long enough and does not overlap
                // with the previously selected palindrome, select it.
                if (r - l + 1 >= k && l > end) 
                {
                    ++ans;
                    end = r;

                    // Since we want the maximum number of non-overlapping
                    // substrings, greedily taking the first valid palindrome
                    // with the earliest possible ending position is optimal.
                    break;
                }
                // Try a larger palindrome around the same center.
                --l;
                ++r;
            }
        }
    }

    return ans;
}

};