class Solution {
public:
    // The idea is to fix the first and 3rd index as one of the character and all of unique inside is our answer.

    int countPalindromicSubsequence(string s) {
        int n=s.size();
        vector<int>st(26,1e6),last(26,-1);//st keeps track of the first index of occurence of a particular character and 'last' last index

        for(int i=0;i<n;++i) last[s[i]-'a']=i;

        for(int i=n-1;i>=0;--i) st[s[i]-'a']=i;

        int ans=0;
        for(int i=0;i<26;++i)
        {
            int first=st[i];
            int end=last[i];
            if(first==1e6 || end==-1 || (first==end)) continue;

            // int no_of_inside_elements=(end-first-1);
            // ans+=no_of_inside_elements; // Since it says, we need to have unique palindromes so, can't just simply take all of the elements

            set<char>st;
            st.insert(s.begin()+first+1,s.begin()+end); // Now set will store the unique characters.
            ans+=(st.size());
        }
        return ans;
    }
};