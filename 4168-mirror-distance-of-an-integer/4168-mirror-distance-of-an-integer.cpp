class Solution {
public:
    int mirrorDistance(int n) {
        int ans=n,rev=0;
        while(n)
        {
            rev=rev*10+n%10;
            n/=10;
        }
        return ans=abs(ans-rev);
    }
};