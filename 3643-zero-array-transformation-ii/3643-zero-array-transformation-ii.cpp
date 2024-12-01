class Solution {
public:
    // The idea is to use Binary Search as any value less than required 'k' is not supportive and all the values onward 'k' 
    // can be our ans.
    // And check for any particular value 'k' required O(N) traversal. 
    // so, overall TC: O(Nlog(N))
    bool check(vector<int>nums,vector<vector<int>>&queries,int mid)
    {
        int len=nums.size();
        vector<int>action(len+1);

        for(int i=0;i<mid;++i)
        {
            int l=queries[i][0];
            int r=queries[i][1];
            int val=queries[i][2];

            action[l]+=val;
            action[r+1]-=val;
        }

        int curr=0;
        for(int i=0;i<len;++i)
        {
            curr+=action[i];
            nums[i]-=curr;

            if(nums[i]>0) return false;
        }

        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int len=nums.size();
        int m=queries.size();

        int l=0, h=m;
        int ans=-1;

        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(check(nums,queries,mid))
            {
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};