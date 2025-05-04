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

            if(curr[0]!=curr[1] && freq.find({curr[1],curr[0]})!=freq.end()) ans+=freq[{curr[1],curr[0]}];

            if(--freq[curr]==0) freq.erase(curr);
        }
        return ans;
    }
};