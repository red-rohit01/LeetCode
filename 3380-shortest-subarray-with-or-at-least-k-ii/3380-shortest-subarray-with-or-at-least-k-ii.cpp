class Solution {
public:
    // The idea is to use sliding window 
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if(k==0) return 1;
        long long val=0;
        int n=nums.size();
        int ans=INT_MAX;
        int i=0;
        int j=0;
        vector<int>pre(32);
        while(j<n)
        {
            val|=(1LL*nums[j]);
            //cout<<val<<" ";
            long long temp=1LL*nums[j];
            for(int l=0;l<32;++l)
            {
                int curr=(1&temp);
                temp/=2;
                if(curr>0) pre[l]++;  
            }
            
            //cout<<pre[0]<<" "<<pre[1]<<"\n";
            
            while(val>=(1LL*k))
            {
                ans=min(ans,j-i+1);
                
                long long temp=nums[i];
                for(int l=0;l<32;++l)
                {
                    int curr=(1&temp);
                    temp/=2;
                    if(curr>0) pre[l]--;
                    
                    if(pre[l]==0 && curr==1) val-=(1LL<<l);
                }   
                i++;
            }
            j++;
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};