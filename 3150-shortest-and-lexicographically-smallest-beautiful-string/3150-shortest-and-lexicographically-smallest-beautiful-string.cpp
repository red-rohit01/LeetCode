class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans="";
        int n=s.size();
        int i=0;
        int j=0;
        int cnt=0;
        while(j<n)
        {
            if(s[j]=='1') cnt++;
            
            while(cnt==k)
            {
                string temp=s.substr(i,(j-i+1));
                if(ans=="")
                {
                    ans=temp;
                }
                else if(temp.size()<ans.size())
                {
                    ans=temp;
                }
                else if(temp<ans && temp.size()==ans.size()) ans=temp;
                
                if(s[i]=='1')
                {
                    cnt--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};