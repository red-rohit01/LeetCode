class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int l=1,h=n/2;
        vector<int>increasingSeq(n);
        for(int i=n-1;i>=0;--i)
        {
            increasingSeq[i]=1;
            int j=i-1;
            while(j>=0 && nums[j]<nums[j+1])
            {
                increasingSeq[j]=1+increasingSeq[j+1];
                j--;
            }
            i=j+1;
        }
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            bool flag=false;
            for(int i=0;i<(n-mid);++i)
            {
                if(increasingSeq[i]>=mid && increasingSeq[i+mid]>=mid)
                {
                    flag=true;
                    break;
                }
            }
            if(flag) l=mid+1;
            else h=mid-1;
        }
        return (l-1);
    }
};