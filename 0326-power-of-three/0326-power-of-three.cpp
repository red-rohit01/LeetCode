class Solution {
public:
    // If n is a power of 3, then it divides every larger power of 3 exactly.
    // For example:
    // 3^4 = 81 is divisible by 3^2 = 9
    // 3^6 = 729 is divisible by 3^1 = 3
    // 3^19 = 1162261467 --> This is the largest power of 3 within 'int'
    
    bool isPowerOfThree(int n) {
        return (n>0 && 1162261467%n==0);
    }
};