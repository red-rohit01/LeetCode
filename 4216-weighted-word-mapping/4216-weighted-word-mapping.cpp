class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        int n=words.size();
        for(int i=0;i<n;++i)
        {
            string curr=words[i];
            int len=curr.size();
            int cnt=0;
            for(int j=0;j<len;++j) cnt+=weights[curr[j]-'a'];

            int ind=cnt%26;
            ans+=static_cast<char>('z'-ind);
        }
        return ans;
    }
};