class Solution {
public:
    // Input: s = "11011000"

    // Find balanced chunks (count = 0 points):
    // 1 1 0 1 1 0 0 0
    // ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓
    // 1 2 1 2 3 2 1 0 ← count values
    //               ↑
    //              count=0 → found chunk "11011000"

    // Since it's one chunk, extract inner: "101100" [Removed the first '1' and last '0']

    // Recursively process "101100":
    // 1 0 1 1 0 0
    // ↓ ↓ ↓ ↓ ↓ ↓ 
    // 1 0 1 2 1 0 ← count values
    //   ↑       ↑
    // Chunks: "10" and "1100"

    // Process "10": inner="" → ""
    // Result: "1" + "" + "0" = "10"

    // Process "1100": inner="10"
    // Recursively on "10":
    //     1 0 
    //     ↓ ↓
    //     1 0 ← found "100"
    //     Inner: "" → base case → ""
    //     Result: "1" + "" + "0" = "10"
    // Result: "1" + "10" + "0" = "1100"

    // Chunks: ["10", "1100"]
    // Sort descending: ["1100", "10"]
    // Join: "110010"

    // Final wrap: "1" + "110010" + "0" = "11100100"

    // Time complexity: O(n^2logn)

    // Finding chunks: O(n) per level
    // Sorting chunks: O(k log k) where k ≤ n
    // Recursion depth: O(n) in worst case
    // String operations (substring, join): O(n)
    // Overall: O(n² log n) worst case

    string makeLargestSpecial(string s) {
        int cnt=0;
        int n=s.size();
        int i=0;

        vector<string>res;
        for(int j=0;j<n;++j)
        {
            // Track balance: +1 for '1' and -1 for '0'
            if(s[j]=='1') cnt+=1;
            else cnt-=1;

            if(cnt==0)
            {
                // maximize the inner part and wrap with 1....0
                res.push_back("1"+makeLargestSpecial(s.substr(i+1,(j-i-1))) + "0");
                i=j+1;  // Move to next potential chunk
            }
        }

        sort(res.begin(),res.end(), greater<string>()); // sort in descending order

        string ans="";
        for(auto &str:res)
        {
            ans+=str;
        }
        return ans;
    }
};