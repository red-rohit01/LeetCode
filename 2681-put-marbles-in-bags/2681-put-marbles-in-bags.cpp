class Solution {
public:
    // Each of the subarray only contributes two numbers to the sum.
    // Since the score of a subarray only matters with its two ends, we can tell that the total score equals the sum of 
    // the first element, the last element, and the sum of every pair (two adjacent ends at each split).
    // k distributions require (k-1) split
    // Detailed explanation in Editorial Page
    long long putMarbles(vector<int>& weights, int k) {
        if(k==1)  return 0;
        
        int n=weights.size();
        vector<long long>rk(n-1);
        for(int i=0;i<(n-1);++i) rk[i]=(weights[i]+weights[i+1]);
        
        
        sort(rk.begin(),rk.end());
        long long mn=0;
        for(int i=0;i<(k-1);++i) mn+=1LL*rk[i];

        long long mx=0;
        for(int i=(n-2);i>=(n-k);--i)  mx+=1LL*rk[i];

        return (mx-mn);
    }
};