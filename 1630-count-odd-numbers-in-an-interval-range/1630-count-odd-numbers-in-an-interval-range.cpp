class Solution {
public:
    int countOdds(int low, int high) {
        int a=(low+1)/2;
        int b=(high+1)/2;

        int ans=(b-a);

        if(low%2==1) ans++;

        return ans;
    }
};