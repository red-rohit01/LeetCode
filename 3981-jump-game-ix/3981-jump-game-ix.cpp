class Solution {
public:
    // Think of the array as a directed graph where edges represent valid jumps.
    // The maximum reachable value from i is the maximum value in the respective component.
    // You can find connected ranges by looking at prefix maximums and suffix minimums, a 
    // cut happens where all values to the left are <= all values to the right. 

    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n),post(n);
        pre[0]=nums[0];
        post[n-1]=nums[n-1];
        for(int i=1;i<n;++i)
        {
            pre[i]=max(pre[i-1],nums[i]);
            post[n-i-1]=min(post[n-i],nums[n-i-1]);
        }

        vector<int>ind;   // To store the cuts 
        for(int i=0;i<n-1;++i)
        {
            if(pre[i]<=post[i+1]) ind.push_back(i);
        }

        vector<int>ans(n);
        if(ind.empty())
        {
            for(int i=0;i<n;++i) ans[i]=pre[n-1];
            return ans;
        }
        for(int i=0;i<=ind[0];++i) ans[i]=pre[ind[0]];

        int sz=ind.size();

        for(int l=0;l<sz-1;++l)
        {
            for(int i=ind[l]+1;i<=ind[l+1];++i) ans[i]=pre[ind[l+1]];
        }

        for(int i=ind[sz-1]+1;i<n;++i) ans[i]=pre[n-1];
        return ans;
    }
};