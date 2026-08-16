class Solution {
public:
    // Case 1: cnt0 is even
    // If the number of stones divisible by 3 is even, Alice wins if there is at least one stone with remainder 1 and at least one stone with remainder 2.

    // Case 2: cnt0 is odd
    // When cnt0 is odd, the difference between the number of remainder 1 and remainder 2 stones matters.

    // Alice wins only when: abs(cnt1 - cnt2) > 2


    bool stoneGameIX(vector<int>& stones) {
        int cnt0=0;
        int cnt1=0;
        int cnt2=0;

        for(int &x:stones) 
        {
            if(x%3==0) cnt0++;
        
            else if(x%3==1) cnt1++;
            
            else cnt2++;
        }

        if(cnt0%2==0) return cnt1>0 && cnt2>0;
        
        return abs(cnt1 - cnt2)>2;
    }
};