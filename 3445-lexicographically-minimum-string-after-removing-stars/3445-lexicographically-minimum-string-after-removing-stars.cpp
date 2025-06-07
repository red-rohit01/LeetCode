class Solution {
public:
    string clearStars(string s) {
        int n=s.size();
        string ans="";
        multiset<pair<char,int>>st;      // multiset erases the first occurence using iterator
        map<int,char>rk;
        for(int j=0;j<n;++j)
        {
            if(s[j]!='*')    // When non '*' character found
            {
                st.insert({s[j], -1*j});
            }
            else
            {
                auto itr=*(st.begin());
                st.erase(itr);
            }
        }
        for(auto &x:st)
        {
            int ind=-1*x.second;
            rk[ind]=x.first;
        }
        for(auto &x:rk) ans+=x.second;
        
        return ans;
    }
};