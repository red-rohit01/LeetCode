class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        int n=power.size();
        map<long long,long long>freq;
        for(auto &x:power) freq[x]++;

        sort(power.begin(),power.end());
        long long ans=1LL*power[0]* (1LL*freq[power[0]]);

        vector<long long>uniq;
        for(auto &x:freq) uniq.push_back(x.first);

        int len=uniq.size();
        vector<long long>dp(len);
        dp[0]=1LL*power[0]*(1LL*freq[power[0]]);

        for(int i=1;i<len;++i)
        {
            dp[i]=dp[i-1];
            long long curr=1LL*uniq[i];
            long long prev=i-1;
            while(prev>=0 && ((uniq[prev]==curr-1) || (uniq[prev]==curr-2))) prev--;

            if(prev>=0) dp[i]=max(dp[i], dp[prev]+ (curr* 1LL*freq[curr]));
            else dp[i]=max(dp[i],(curr*1LL*freq[curr]));
        }
        return dp[len-1];
    }
};