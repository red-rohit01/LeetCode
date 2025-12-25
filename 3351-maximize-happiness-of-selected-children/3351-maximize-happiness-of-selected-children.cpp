class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int>pq;
        for(auto &x:happiness) pq.push(x);

        long long ans=0;
        long long minus=0;
        while(k--)
        {
            long long temp=pq.top();
            pq.pop();
            temp=max(0LL,temp-minus);
            ans+=temp;
            minus++;
        }

        return ans;
    }
};