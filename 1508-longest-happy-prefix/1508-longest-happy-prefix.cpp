class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        vector<int>Z(n);
        int ans=0;
        string res="";
        for(int i=1,l=0,r=0;i<n;++i)
        {
            if(i<=r) Z[i]=min(r-i+1,Z[i-l]);
            while((i+Z[i])<n && s[i+Z[i]]==s[Z[i]]) Z[i]++;
            if((i+Z[i]-1)>r)
            {
                l=i;
                r=i+Z[i]-1;
            }
            if(Z[i]>ans && Z[i]==(n-i))   // If the length of Z[i] equals the remaining length till 'n'
            {
                ans=Z[i];
                res=s.substr(n-Z[i]);
            }
        }
        return res;
    }
};