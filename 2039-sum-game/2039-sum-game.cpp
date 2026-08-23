class Solution {
public:
    // count question marks:
    // leftQ  = number of '?' in first half, rightQ = number of '?' in second half
    // Each ? can become any digit from 0 to 9.

    // A question mark on the left can increase diff.
    // A question mark on the right can decrease diff.

    // The key trick: Bob can force equality only when the unknown digits can perfectly compensate the current diff.

    // Observation
    // Each player controls exactly half of the ? positions overall only if the number of ? is even.
    // If the total number of ? is odd, Alice gets one extra move. That extra move is enough to break equality. So:

    // if total ? is odd: Alice wins
    // Now assume total ? is even.

    // The net effect of unmatched question marks is:
    // needed balance = (rightQ - leftQ) / 2 * 9
    // Why 9?

    // Because in optimal play, one side can offset the other by at most 9 per extra question mark pair.
    // Bob wins only if: diff == needed balance
    // Otherwise Alice wins.

    double getExpectation(char c)
    {
        return c=='?'?4.5:(c-'0');
    }
    bool sumGame(string num) {
        int n=num.size();
        double ans=0.0;

        for(int i=0;i<n/2;++i) ans+=getExpectation(num[i]);

        for(int i=n/2;i<n;++i) ans-=getExpectation(num[i]);

        return (ans!=0.0);
    }
};