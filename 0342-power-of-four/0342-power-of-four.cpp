class Solution {
public:
    bool isPowerOfFour(int n) {
    if(n<=0) return false;
    //A Number is power of 4 if the number is power of 2 and it gives remainder 1 on being divided by 3.

    return (n&(n-1))==0 && n%3==1;
    }
};