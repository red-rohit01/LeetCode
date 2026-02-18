class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last=(n&1);
        n=n/2;
        while(n>0)
        {
            if(last==(n&1))
                return false;
            
            last=(n&1);
            n=n/2;
        }
        return true;
    }
};