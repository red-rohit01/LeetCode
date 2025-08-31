class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i:nums) mp[i]++;
        
        vector<vector<int>>bucket(n+1);
        for(auto& it:mp)
        {
            int element=it.first;
            int freq=it.second;
            bucket[freq].push_back(element);
        }


        vector<int>res;
        for(int i=n;i>0;--i)
        {
            if(bucket[i].size()==0) continue;

            while(bucket[i].size()>0 && k>0)
            {
                res.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
            if(k==0) return res;
        }
        return res;

        // int n=nums.size();
        // if(k==n) return nums;
        // unordered_map<int,int>rk;

        // for(int i=0;i<n;++i) rk[nums[i]]++;

        // // Initialize a heap with the most frequent elements at the top
        // auto comp=[&rk](int a,int b)
        // {
        //     return rk[a]>rk[b];
        // };
        // priority_queue<int,vector<int>,decltype(comp)>pq(comp);
        // // O(N*logk)<O(N*logN)
        // for(auto &x: rk)
        // {
        //     pq.push(x.first);
        //     if(pq.size()>k) pq.pop();
        // }

        // vector<int>ans;
        // for(int i=k-1;i>=0;--i)
        // {
        //     auto x=pq.top();
        //     pq.pop();
        //     ans.push_back(x);
        // }
        // return ans;
    }
};