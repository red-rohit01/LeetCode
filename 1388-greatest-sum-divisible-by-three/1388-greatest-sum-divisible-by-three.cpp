class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp1(3),temp2(3);
        for(int i=0;i<n;++i)
        {
            int a=nums[i];
            for(int j=0;j<3;++j)
            {
                int b=temp1[j]+a;
                int s=b%3;
                temp2[s]=max(b,temp2[s]); //Taking 'max' here as index 's' can be updated by any of three 'j'. so, we should populate with the mxm one
            }
            temp1=temp2;
        }
        return temp2[0];
    }
};