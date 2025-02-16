class Solution {
public:
    // Idea is get the maxm char and try to get the maxm substring
    string answerString(string word, int numFriends) {
        if(numFriends==1) return word;
        int n=word.size();
        char c=word[0];
        for(auto &x:word)
        {
            c=max(c,x);
        }

        string ans="";
        ans+=c;
        for(int i=0;i<n;++i)
        {
            if(word[i]==c)
            {
                int rem_len=(n-i);
                int curr=numFriends-i;   // Here 'i' number of prev characters can be assigned to each friend

                if(curr>=1) rem_len-=(curr-1);
                ans=max(ans,word.substr(i,rem_len));
            }
        }
        return ans;
    }
};