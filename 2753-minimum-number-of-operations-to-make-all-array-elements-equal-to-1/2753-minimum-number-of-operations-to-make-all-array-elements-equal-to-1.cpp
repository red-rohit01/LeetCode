class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int op=0;
        for (int i=0;i<n;++i) 
        { 
            if(nums[i]==1) op++;
        } 
     
        if (op!=0) return (n-op); 
     
        int ans = INT_MAX; 
        for (int i=0;i<n;++i) 
        { 
            int num=nums[i]; 
            for (int j =i+1;j<n;++j) 
            { 
                num = gcd(num,nums[j]); 
                if (num == 1) 
                { 
                    ans = min(ans, j-i+(n-1)); 
                    break; 
                } 
            } 
        } 
     
        if (ans == INT_MAX) return -1; 
        return ans; 
    }
};