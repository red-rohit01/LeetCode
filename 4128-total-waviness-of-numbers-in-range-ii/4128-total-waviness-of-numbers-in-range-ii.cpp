class Solution {
public:
    // we'll use Digit DP, This is a technique where we build numbers digit-by-digit, from left to right

    // When we discover that prev successfully forms a peak or a valley, that wave point will exist in every 
    // single variation of the numbers we can finish building downstream. So, we do (add*count) to our running waviness score.
    // The value of 'add' can be {0,1} only.
    
    struct Node {
        long long cnt;   // How many valid numbers can be finished from this point
        long long wav;   // Total wave score accumulated across all those numbers
    };

    string s;
    Node dp[20][2][11][11];  // DP state: dp[index][is_StartedPrinting][lastdigit][secondLastdigit] == {cnt, wav}
    bool vis[20][2][11][11];

    // why do we even require is_StartedPrinting?
    // e.g., if num = 767229334352
    // To get to the point from left-to-right, where we're evaluating 352
    // we would be covering like this: 00000000352 

    // If tight==true, it means: Every digit chosen so far exactly matches the prefix of n. so, future digits are restricted.

    // Example where ignoring tight breaks things
    // Suppose: n = 5487
    // and we're at:  dfs(pos=2, started=1, last=4, secondLast=5, tight=true)

    // We're deciding the third digit.
    // Because: prefix built=54

    // and we still exactly match the prefix of 5487.

    // The next digit cannot exceed: 8
    // So choices are: 0..8

    // Now imagine another call:

    // dfs(pos=2, started=1, last=4, secondLast=5, tight=false)
    // Same state except for tight.

    // Now we're already below the upper bound.

    // Choices become: 0..9

    // These two states clearly have different answers.
    // One explores: 0..8
    // The other explores: 0..9

    // Therefore: dp[2][1][4][5] cannot represent both.

    // Since memoization is not on the 'tight' variable that's why we are doing the above explicit check. 
    // The other way would be to include this variable 'tight' in the dp too as: dp[pos][started][last][secondLast][tight] 
    // and then memoization becomes: if(vis[pos][started][last][secondLast][tight])   return dp[...];

    // But this is not a very good optimization:
    // In fact, during a run of solve(n):
    //      --> There is essentially only one "tight path" at each level.
    //      --> As soon as you choose a smaller digit, you move into tight=false.

    // Most of the reusable work is in the tight=false states.

    Node dfs(int pos, int started, int last, int secondLast, bool tight) 
    {
        if (pos==s.size()) return {1, 0};

        if (!tight && vis[pos][started][last][secondLast]) return dp[pos][started][last][secondLast];

        int limit=tight?s[pos]-'0':9;

        Node res={0,0};

        for(int d=0;d<=limit;++d) 
        {
            bool ntight=tight && (d==limit);

            if(!started && d==0) 
            {
                Node nxt=dfs(pos + 1, 0, 10, 10, ntight);

                res.cnt += nxt.cnt;
                res.wav += nxt.wav;
            } 
            else 
            {
                long long add=0;        // we can use a bool value here too and then conditional addition of nxt.cnt

                if (started && secondLast!=10) 
                {
                    if((last>secondLast && last>d) || (last<secondLast && last<d)) add=1;
                }

                int nSecondLast=started?last:10;
                int nLast=d;

                Node nxt=dfs(pos+1, 1, nLast, nSecondLast, ntight);

                res.cnt+=nxt.cnt;
                res.wav+=nxt.wav + add * nxt.cnt;
            }
        }

        if (!tight) 
        {
            vis[pos][started][last][secondLast]=true;
            dp[pos][started][last][secondLast]=res;
        }

        return res;
    }

    long long solve(long long n) 
    {
        if(n<=100) return 0;

        s=to_string(n);
        memset(vis, 0, sizeof(vis));

        return dfs(0, 0, 10, 10, true).wav;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};