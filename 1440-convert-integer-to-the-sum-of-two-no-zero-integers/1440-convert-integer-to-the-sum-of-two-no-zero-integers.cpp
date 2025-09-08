class Solution {
public:
    bool check(int a,int b)
    {
        while(a)
        {
            int dig=a%10;
            if(dig==0) return false;
            a/=10;
        }

        while(b)
        {
            int dig=b%10;
            if(dig==0) return false;
            b/=10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<n;++i)
        {
            int j=n-i;
            if(check(i,j)) return {i,j};
        }
        return {-1};
    }
};