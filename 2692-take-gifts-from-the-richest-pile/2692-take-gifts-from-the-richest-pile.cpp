class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans=0;
        priority_queue<int>pq;
        for(int i=0;i<gifts.size();++i)
        {
            pq.push(gifts[i]);
        }
        while(k--)
        {
            int temp=pq.top();
            pq.pop();
            int s=sqrt(temp);
            pq.push(s);
        }
        while(!pq.empty())
        {
            long long temp=1LL*pq.top();
            pq.pop();
            ans+=temp;
        }
        return ans;
    }
};