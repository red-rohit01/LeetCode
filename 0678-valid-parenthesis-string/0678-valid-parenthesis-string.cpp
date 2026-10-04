class Solution {
public:
    bool checkValidString(string s) {                    // (*(  ->  min_open=1, max_closing_need=3
        int n=s.size();
        int min_open=0,max_closing_need=0;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='(')
            {
                min_open++;
                max_closing_need++;
            }
            else if(s[i]==')')
            {
                min_open--;
                if(min_open<0) min_open=0;
                max_closing_need--;
            }
            else 
            {
                min_open--;
                if(min_open<0) min_open=0;
                max_closing_need++;
            }

            if(max_closing_need<0) return false;
        }
        return (min_open==0);
    }
};