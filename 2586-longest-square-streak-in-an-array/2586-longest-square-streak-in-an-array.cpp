class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());   //Sorted in decreasing order  
        map<int,int>rk;
        int n=nums.size();
        for(int i=0;i<n;++i)
        {
            rk[nums[i]]++;
        }
        
        int mx=1;
        for(int i=0;i<n-1;++i)
        {
            int cnt=1;
            int x=nums[i];
            int p=sqrt(x);
            while(rk[p]>0)
            {
                if(p*p ==x) cnt++;
                else break;
                rk[p]--;          
                x=p;
                p=sqrt(x);
            }
            mx=max(mx,cnt);
        }
        
        return mx==1?-1:mx;
    }
};