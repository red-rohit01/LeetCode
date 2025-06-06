class Solution {
public:
    long long helper(string num,string s,int limit)
    {
        int n=num.size();
        int m=s.size();

        if(n<m) return 0;

        if(n==m) return (num>=s?1:0);      // If my 'num' is 764 and I need to use suffix as '234' Then there is only one way.

        string s_=num.substr(n-m,m);      // Last 'm' length suffix if num=="86794" and m==2. Then, s_="94"

        long long ans=0;
        int l=n-m;

        for(int i=0;i<l;++i)
        {
            if(limit<(num[i]-'0'))
            {
                ans+=(long long)pow(limit+1,l-i); //if current digit is larger than limit then we can take all combinations with limit+1 (including 0) digits
                return ans;
            }

            ans+=(long long)(num[i]-'0')*(long long)pow(limit+1,l-i-1);
            //0 to num[i]-1 have no problem with rest of digits [0->limit]
            //for num[i] we need to check the rest of digits to ensure all combinations do not exceed the num
        }

        if(s_>=s) ans++;    // Since, The above for loop was check only for remaining prefix. That's why this extra check for equal length as 's'

        return ans;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string start_=to_string(start-1);
        string finish_=to_string(finish);

        return helper(finish_,s,limit)-helper(start_,s,limit);
    }
};