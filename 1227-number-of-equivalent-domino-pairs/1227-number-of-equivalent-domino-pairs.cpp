class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n=dominoes.size();
        int ans=0;
        map<vector<int>,int> freq;
        for(auto &x:dominoes) freq[x]++;
        

        for(int i=0;i<n;++i)
        {
            vector<int>curr=dominoes[i];
            int cnt=freq[curr];

            ans+=(cnt-1);

            vector<int>other={curr[1],curr[0]};
            if(curr!=other && freq.find(other)!=freq.end()) ans+=freq[other];

            if(--freq[curr]==0) freq.erase(curr);
        }
        return ans;
    }
};