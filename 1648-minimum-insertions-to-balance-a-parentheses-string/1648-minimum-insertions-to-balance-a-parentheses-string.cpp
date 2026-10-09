class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        int res=0;
        int right=0;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='(')
            {
                if(right%2==1)
                {
                    right--;
                    res++;
                }
                right+=2;
            }
            else
            {
                right--;
                if(right<0)
                {
                    right+=2;
                    res++;
                }
            }
        }
        res+=right;
        return res;
    }
};