class Solution {
public:
    int halveArray(vector<int>& nums) {
        int n=nums.size();
        int op=0;
        double total=0;
        priority_queue<double>pq;
        for(auto &x:nums) 
        {
            total+=(double)x;
            pq.push((double)x);
        }

        double curr=total;
        while(!pq.empty() && total<2*curr)
        {
            double val=pq.top();
            pq.pop();
            curr-=val;
            curr+=(val/2.0);
            pq.push(val/2.0);
            op++;
        }
        return op;
    }
};