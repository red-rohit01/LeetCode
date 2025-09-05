class Solution {
public:
    // Just Maths: num1-num2*k={2^i+2^i+2^i+.....}(k times)
    int makeTheIntegerZero(int num1, int num2) {
        if(num2>num1) return -1;

        for(int k=1;k<=32;++k)
        {
            long long val=1LL*num1-(num2*1LL*k);
            if(val<=0 || val<k) return -1;
            int cnt=0;
            while(val)
            {
                int dig=(val&1);
                if(dig==1) cnt++;
                val=val>>1;
            }
            if(cnt<=k) return k;
        }
        return -1;
    }
};