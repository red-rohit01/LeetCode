class Solution {
public:
    const int mod=1000000007;
    
   int extendedGCD(int a,int b, int& x, int& y)
   {
      if(b==0)
      {
         x=1;
         y=0;
         return a;
       }
    int x1,y1;
    int g=extendedGCD(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return g;
   }  
    int countGoodStrings(int low, int high, int zero, int one) {
       /* long long ans=0;
        while(low<=high)
        {
            if(low%g==0)
            {
                //zero replaced by->a;
                //one replaced by->b;
                 int x=0,y=0;
                 int g=extendedGCD(a,b,x,y);
                int x1=(x*low)/g;
                int y1=(y*low)/g;
                int k=-x1/(b/g);
                if((-x1)%(b/g) !=0) k++;
                int l=y1/(a/g);
                int diff=(l-k+1);
                ans=(ans%mod + diff%mod)%mod;     //It will count the number of different solutions of ax+by=c;
            }
            low++;                             
        }
        return ans; */
        
        vector<int>dp(high+1);
        dp[0]=1;
        int ans=0;
        for(int i=1;i<=high;++i)
        {
            if(i>=zero) dp[i]=(dp[i]%mod + dp[i-zero] %mod)%mod;
            if(i>=one) dp[i]=(dp[i]%mod + dp[i-one] %mod)%mod;
            
            dp[i]=dp[i]%mod;
            if(i>=low) ans=(ans%mod + dp[i]%mod)%mod;
        }
        return ans;
    }
};