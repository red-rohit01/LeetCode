class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans=0;
        while(numExchange<=numBottles)
        {
            numBottles=numBottles-numExchange;
            numBottles+=1;
            ans+=numExchange;    // Since we would have drunk `numExchange` number of full bottles to make them empty
            numExchange++;
        }
        int drunkBottles=(ans+numBottles);  //At the end, I have to drink all the remaining numBottles as I can't exchange them now
        return drunkBottles;
    }
};