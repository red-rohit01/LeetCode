class Solution {
public:
    unordered_map<int, unordered_map<int, double>>dp;
    double helper(int A, int B) 
    {
        if(A==0 && B!=0) return 1;
	
        else if(A==0 && B==0) return 0.5; // since the problem itself tells us to use half of the probability that both soups are used up in the same turn.

        else if(A!=0 && B==0) return 0;
						
        if(dp[A][B]!=0) return dp[A][B];
			
        double prob=0;
        prob += 0.25*helper(A-min(A,100),B);
        prob += 0.25*helper(A-min(A,75),B-min(B,25));
        prob += 0.25*helper(A-min(A,50), B-min(B,50));
        prob += 0.25*helper(A-min(A,25),B-min(B,75));
				
        return dp[A][B]=prob;
    }
    double soupServings(int n) {
        if(n>=4800) return 1.0;

        else return helper(n,n);
    }
};