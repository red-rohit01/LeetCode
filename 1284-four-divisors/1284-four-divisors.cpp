class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;++i)
        {
            int val=nums[i];
            int cnt=2;
            int temp=val+1;
            bool flag=true;
            for(int j=2;j*j<=val;++j)
            {
                if(cnt>4)
                {
                    flag=false;
                    break;
                }
                if(val%j==0)
                {
                    if(j==(val/j))
                {
                    cnt++;
                    temp+=j;
                }
                else
                {
                    cnt+=2;
                    temp+=j;
                    temp+=(val)/j;
                }
                }
            }
            if(flag && cnt==4)
            {
                ans+=temp;
            }
        }
        return ans;
    }
};