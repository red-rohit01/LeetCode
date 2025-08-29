class Solution {
public:
    // We can see that Alice can only win the game if (x+y) is an odd number
    long long flowerGame(int n, int m) {
        long long oddx=0, eveny=0, evenx=0, oddy=0;
        evenx=n/2;
        oddx=(n-evenx);
        eveny=m/2;
        oddy=(m-eveny);
        
        return oddx*eveny + evenx*oddy;
    }
};