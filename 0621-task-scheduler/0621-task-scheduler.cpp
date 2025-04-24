class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m=tasks.size();
        if(n==0) return m;

        map<char,int>rk;
        for(int i=0;i<m;++i) rk[tasks[i]]++;

        priority_queue<int>pq;   // To push the frequency of each Task

        for(auto &x:rk) pq.push(x.second);

        int ans=0;
        while(!pq.empty())
        {
            vector<int>remaining;
            int one_unit=n+1; 

            while(!pq.empty() && one_unit>0)
            {
                int mx=pq.top(); 
                pq.pop();
                mx--;
                if(mx>=1) remaining.push_back(mx); 

                ans++; 
                one_unit--; 
            }

            for(auto &x:remaining)
                pq.push(x); 

            if(pq.empty()) break; 

            ans+=one_unit;                             // Add the remaining even if the pq got empty in this iteration
        }
        return ans;
    }
};