class Solution {
public:
    /*
        1%7==1
        11%7=4
        111%7= (11%7 * 10 +1)%7= 41%7=6
        1111%7= (111%7 *10 +1)%7 = 61%7=5
        11111%7= (1111%7 *10 +1)%7 = 51%7 =2
        111111%7= (11111%7 *10 +1)%7 = 21%7=0
    */
    int smallestRepunitDivByK(int k) {
        if (k==1) return 1;

        // Numbers made of only 1s can never be divisible by 2 or 5
        if (k%2==0 || k%5==0) return -1;

        int rem=0;
        for(int i=1;i<=k;++i) 
        {
            rem=(rem*10+1)%k;
            if(rem==0) return i;
        }
        return -1;
    }
};