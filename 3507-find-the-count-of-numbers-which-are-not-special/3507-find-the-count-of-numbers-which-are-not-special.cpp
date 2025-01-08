class Solution {
public:
    // The idea is simple as per the conditions given in the problem. Only squares of prime numbers can be a special number.
    int nonSpecialCount(int l, int r) {
        vector<int>primes;
        int temp=sqrt(r);
        temp++;
        vector<int>sieve(temp+1,1);
        sieve[0]=0;
        sieve[1]=0;
        for(int i=2;(i*i)<=temp;++i)
        {
            for(int j=(i*i);j<=temp;j+=i) sieve[j]=0;
        }

        for(int i=2;i<=temp;++i)
        {
            if(sieve[i]) primes.push_back(i);
        } 

        int total=(r-l+1);
        int special=0;

        int len=primes.size();
        for(int i=0;i<len;++i)
        {
            int curr=primes[i]*primes[i];
            if(curr>r) break;

            if(curr>=l && curr<=r) special++;
        }
        return (total-special);
    }
};