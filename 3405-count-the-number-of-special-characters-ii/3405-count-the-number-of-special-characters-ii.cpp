class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>small(26,-1),big(26,-1);
        int n=word.size();
        for(int i=0;i<n;++i)
        {
            if(word[i]>='a')
            {
                int ind=word[i]-'a';
                small[ind]=max(small[ind],i);
            }
            else
            {
                int ind=word[i]-'A';
                if(big[ind]==-1) big[ind]=i;
            }
        }
        int ans=0;
        for(int i=0;i<26;++i)
        {
            if(small[i]==-1 || big[i]==-1) continue;

            if(small[i]<big[i]) ans++;
        }
        return ans;
    }
};