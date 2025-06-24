class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        vector<int>pre(n+1);
        for(int i=0;i<n;++i)
        {
            if(nums[i]==key)
            {
                int prev=max(0,i-k);
                int nxt=min(n,i+k+1);
                pre[prev]++;
                pre[nxt]--;
            }
        }
        int val=0;
        for(int i=0;i<n;++i)
        {
            val+=pre[i];
            pre[i]=val;
        }

        vector<int>ans;
        for(int i=0;i<n;++i)
        {
            if(pre[i]>0) ans.push_back(i);
        }
        return ans;
    }
};