class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=0;
        while(numBottles>=numExchange)
        {
            ans+=numExchange;
            numBottles=(numBottles-numExchange+1);
        }
        return (ans+numBottles);
    }
};