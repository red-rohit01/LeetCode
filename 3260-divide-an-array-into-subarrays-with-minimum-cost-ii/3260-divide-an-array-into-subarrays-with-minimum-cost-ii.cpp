class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        multiset<long long>l,r;
        int n=nums.size();
        k--;
        long long ans=nums[0];
        for(int i=1;i<=dist+1;++i)
        {
            ans+=nums[i];
            l.insert(nums[i]);
        }
        while(l.size()>k)
        {
            ans-=*l.rbegin();
            r.insert(*l.rbegin());
            l.erase(l.find(*l.rbegin()));
        }
        long long curr=ans;
        for (int i=dist+2;i<n;++i) 
        {
            //erasing element from the window
            if (l.find(nums[i-dist-1])!=l.end()) 
            {
                curr-=nums[i - dist - 1];
                l.erase(l.find(nums[i-dist-1]));
            } 
            else 
            {
                r.erase(r.find(nums[i-dist-1]));
            }
            // Adding an element to the window
            if (nums[i]<*l.rbegin()) 
            {
                curr+=nums[i];
                l.insert(nums[i]);
            } 
            else 
            {
                r.insert(nums[i]);
            }
            // Balancing the set such that the first set has (k - 1) elements 
            while(l.size()<k) 
            {
                curr += *r.begin();
                l.insert(*r.begin());
                r.erase(r.find(*r.begin()));
            }
            while(l.size()>k) 
            {
                curr-=*l.rbegin();
                r.insert(*l.rbegin());
                l.erase(l.find(*l.rbegin()));
            }
            ans=min(ans, curr);
        }
        return ans;
    }
};