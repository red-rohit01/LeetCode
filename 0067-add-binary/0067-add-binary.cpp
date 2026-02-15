class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;
        int n=a.size()-1;
        int m=b.size()-1;

        if(m>n)
        {
            swap(a,b);
            swap(n,m);
        }

        string ans="";
        while(n>=0 && m>=0)
        {
            int rk=a[n--]-'0';
            int dk=b[m--]-'0';

            if((rk+dk)==0)
            {
                if(carry==0)
                {
                    ans+='0';
                }
                else ans+='1';

                carry=0;
            }
            else if((rk+dk)==1)
            {
                if(carry==0)
                {
                    ans+='1';
                }
                else
                {
                    ans+='0';
                    carry=1;
                }
            }
            else 
            {
                if(carry==0)
                {
                    ans+='0';
                    carry=1;
                }
                else
                {
                    ans+='1';
                    carry=1;
                }
            }
        }
        while(n>=0)
        {
            if((a[n--]-'0')==0)
            {
                if(carry==0)
                {
                    ans+='0';
                }
                else ans+='1';

                carry=0;
            }
            else 
            {
                if(carry==0)
                {
                    ans+='1';
                    carry=0;
                }
                else 
                {
                    ans+='0';
                    carry=1;
                }
            }
        }

        if(carry==1) ans+='1';

        reverse(ans.begin(),ans.end());

        return ans;
    }
};