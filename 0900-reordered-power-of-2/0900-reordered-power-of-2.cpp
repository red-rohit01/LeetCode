class Solution {
public:
    // The idea is to check for each of the powers of '2', the frequency of digits [0,1,2,3,4,5,6,7,8,9]. If any of the powers frequency of 
    //digits matches with the original number. Then, I can always arrange the original number accordingly to match this power value.
    vector<int> cnt(int n)
    {
        vector<int>ans(10);
        while(n)
        {
            ans[n%10]++;
            n/=10;
        }
        return ans;
    }
    
    bool reorderedPowerOf2(int n) {
       vector<int>rk;
        rk=cnt(n);
        for(int i=0;i<31;i++)
        {
            if(rk==cnt(1<<i)) return true;
        }
        return false;
    }
};