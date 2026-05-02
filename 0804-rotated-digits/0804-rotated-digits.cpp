class Solution {
public:
    bool check(int num)
    {
        bool flag=false;
        while(num)
        {
            int dig=num%10;
            if(dig==2 || dig==5 || dig==6 || dig==9) flag=true;
            else if(!(dig==0 || dig==1 || dig==8)) return false;

            num/=10;
        }
        return flag;
    }
    int rotatedDigits(int n) {
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            if(check(i)) ans++;
        }
        return ans;
    }
};