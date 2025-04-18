class Solution {
public:
    // Doing in Brute Force manner whatever it says to.
    string countAndSay(int n) {
        string prev="1";
        string ans;
        int i=1;
        while(i<n)
        {
            ans="";
            int a=0,len=prev.size();
            int j=0;
            while(j<len)
            {
                if(prev[j]==prev[a]) j++;
                
                else 
                {
                    int cnt=j-a;
                    ans+=(to_string(cnt)+prev[a]);
                    a=j;
                }
            } 
            int cnt=j-a;
            ans+=(to_string(cnt)+prev[a]);
            prev=ans;
            i++;
        }
        return prev;
    }
};