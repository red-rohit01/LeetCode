class Solution {
public:
    // We add the new row one by one. Apart from its inner adjacent relation, every new added row only relies on the previous one row
    // if the current state is made by 'two colors' (the state int left figure), then we can add another line which is composed of 'two colors' or 'three colors'
    // If the current is composed of 2 colors, then:
    // --> if the new line is composed of 'two colors', there are 3 combinations we can make;
    // --> if the new line is composed of 'three colors', there are 2 combinations we can make;

    // If the current state is composed of 3 colors, then:
    // --> if the new line is composed of 'two colors', there are 2 combinations we can make;
    // --> if the new line is composed of 'three colors', there are 2 combinations we can make;

    // Now we define the state:
    // defind last line with two colors: Y(n);
    // define last line with three colors: W(n);
    // so the formula we can get
    // W[n] = 2*Y[n-1] + 2*W[n-1]
    // Y[n] = 3*Y[n-1] + 2*W[n-1]
    // and the Initial state (that is only one line)
    // Y[1] = 6, W[1] = 6;

    // For diagram by [NerdXie]: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/solutions/574932/simple-solution-with-picture-follow-up-w-ulck/

    int numOfWays(int n) {
        if(n==1) return 12;

        int mod=1e9+7;
        vector<long> threeColor(n+1),twoColor(n+1);
        threeColor[1]=6;
        twoColor[1]=6;

        for(int i=2;i<=n;++i)
        {
            threeColor[i]=(2*twoColor[i-1]+2*threeColor[i-1])%mod;
            twoColor[i]=(3*twoColor[i-1]+2*threeColor[i-1])%mod;
        }
        int res=(threeColor[n]%mod + twoColor[n]%mod)%mod;
        return res;
    }
};