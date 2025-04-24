class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool>rk(n);
        if(n==1) return true;
        rk[0]=true;
        int mx=0;     // maxm length I can go forward from this particular index
        for(int i=0;i<n-1;++i)
        {
            if(rk[i]==0) return false;
            if(rk[i]==true && nums[i]>mx)   // There is no use to traverse if(nums[i]<=mx) as we would have already covered in previous iteration.
            {
                for(int j=i+1;j<n && j<=(i+nums[i]);++j)
                {
                    rk[j]=true;
                }
                mx=nums[i];
            }
            if(rk[n-1]==true) return true;
            mx--;     // The maxm reach from next index would decrease by '1'
        }
        return false;
    }
};