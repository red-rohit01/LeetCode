class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n=nums.size();
        if(value==1) return n;
        
        for(int i=0;i<n;++i)
        {
            nums[i]= nums[i]%value + value;
            nums[i]%=value;
        }
        
        map<int,int>rk;
        for(int i=0;i<n;++i)
        {
            rk[nums[i]]++;
        }
        int val=0;
        while(rk.size()>0)
        {
            int temp=val % value;
            if(rk[temp]>0)
            {
                val++;
                rk[temp]--;
                if(rk[temp]==0) rk.erase(temp);
            }
            else return val;
        }
        return val;
    }
};