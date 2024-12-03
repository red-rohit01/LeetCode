class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        int len=s.size();
        int n=spaces.size();
        int i=0;
        string curr="";
        int ind=0;
        int stop=spaces[ind];
        while(i<len)
        {
            while(i<len && i<stop)
            {
                curr+=s[i];
                i++;
            }

            curr+=" ";
            if(i==len) curr.pop_back();       // If i gets to the last position then, no need of space.
            ans+=curr;

            curr="";
            ind++;
            if(ind<n) stop=spaces[ind];
            else stop=len;
        }
        return ans;
    }
};