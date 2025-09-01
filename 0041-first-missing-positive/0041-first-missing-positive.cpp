class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        //clearly values less than 1 and greater than n is of no use for us.
        for(int i=0;i<n;++i)
        {
            if(nums[i]<1 || nums[i]>n) nums[i]=n+1;
        }

        // Now we are having numbers between [1 and n] and we can use these values as index to mark.
        
        for(int i=0;i<n;++i)
        {
            int val=abs(nums[i]);      // Here we are taking absolute because we are updating negative in the same array so it may be possible that we have updated very further element to negative.

            if(val>n) continue;

            val--; // Here we are following 0 based index.so val-1 and we'll be using this as index
            if(nums[val]>0)
            {
                nums[val]= -1*nums[val];
            }
        }
        // for(int i=0;i<n;++i) cout<<nums[i]<<" ";
        
        //[3,4,-1,1]---> [-3,4,-5,-1]
        // First index at which non-negative value will be our ans

        for(int i=0;i<n;++i)
        {
            if(nums[i]>0) return (i+1);
        }
        return (n+1);
    }
};