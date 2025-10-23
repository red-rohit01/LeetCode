class Solution {
public:
    bool hasSameDigits(string s) {
        int n=s.size();
        for(int op=0;op<n-2;++op)
        {
            int len=s.size();
            string curr="";
            for(int i=0;i<len-1;++i)
            {
                int val=((s[i]-'0')+(s[i+1]-'0'))%10;
                curr+=(char)(val+'0');
            }
            s=curr;
        }
        return (s[0]==s[1]);
    }
};