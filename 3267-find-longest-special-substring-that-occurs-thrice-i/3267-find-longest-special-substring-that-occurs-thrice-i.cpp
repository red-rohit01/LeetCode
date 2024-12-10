class Solution {
public:
    int maximumLength(string s) {
        int n=s.size();
        unordered_map<int,vector<int>>rk;
        for(int i=0;i<n;++i)
        {
            int j=i+1;
            while(j<n && s[j]==s[i]) j++;

            int len=j-i;   // longest similar character substring possible starting from this particular index.
            int ind=s[i]-'a';
            rk[ind].push_back(len);
            i=j-1;
        }
        int ans=0;
        for(auto &x:rk)
        {
            vector<int> v=x.second;   // Length of all the substrings having starting character as 'a', 'b', ..... 
            int len=v.size();
            sort(v.begin(),v.end());
            if(len>=3)
            {
                ans=max(ans,v[len-3]);
            }
            if(len>=2)  // The scenario could be something like [aaaa, aaaaaaaaaaa] then It's possible to have '3' no. of strings
            {           // and the length of one string is min (4, 11-1=10) because from last string I want to have two strings
                ans=max(ans,min(v[len-1]-1,v[len-2]));        // of largest length and this largest length will be (len-1)
            }
            ans=max(ans,v[len-1]-2);     // If we are having only one substring [aaaaaaaaaaa]. Then to get '3' substrings the largest
        }                                         // length possible is (this_len-2);
        if(ans==0) return -1;
        return ans;
    }
};