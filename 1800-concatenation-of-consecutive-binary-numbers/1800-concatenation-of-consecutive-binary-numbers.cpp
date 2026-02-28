class Solution {
public:
    const int mod=1000000007;
    int concatenatedBinary(int n) {
        long long ans=0,length=0;
        for(int i=1;i<=n;++i) 
        {
            if((i&(i-1))==0) length++;
            
            ans=((ans<<length)+i)%mod;
        }
        return ans;
    }
};