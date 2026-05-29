class Solution {
public:
    // However, to understand it mathematically, let's consider a number n with 4 digits:
    // n=abcd
    // Since we are using the base−10 unit system, we can represent n as:
    // n=1000a+100b+10c+d
    // To make the digit sum equal to n:
    // a+b+c+d = 1000a+100b+10c+d

    // We have to add the missing values:
    //    a+      b+    c+d
    //    999a+  99b+  9c+0
    //    1000a+100b+10c+d      =n
    // Rewrite n as: n=999a+99b+9c+ digitSum(n) (a+b+c+d)
    
    // Thus, we can isolate the digitSum(n):

    // digitSum(n) =n−999a+99b+9c 
    //             =n−9x(111a+11b+1c)
    
    // Back to n=abcd, if we perform integer division by 10, we have

    // floor(n/10)=abc

    // In its expanded form, it is equivalent to: abc=100a+10b+c
    // Similarly:             floor(n/100)=10a+b
    //                        floor (n/1000) = a
    // Now, we can replace the grouped terms in the digit sum formula:

    // digitSum(n) = n-999a-99b-9c
    //             = n-9(111a+11b+c)
    //             = n-9(100a+10b+c   + 10a+b   + a)
    //             = n−9(⌊n/10⌋ + ⌊n/100⌋ + ⌊n/1000⌋)

    // In our code, we include +⌊n/10000⌋ to accommodate the maximum possible value of n under the given constraints.

    // Finally, return global minimum digit sum
    int minElement(vector<int>& nums) {
        int res=36;
        for(auto& n:nums) res=min(res, n-9*((n/10) + (n/100) + (n/1000) + (n/10000)));
        
        return res;
    }
};