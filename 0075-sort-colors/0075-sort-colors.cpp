class Solution {
public:
    // One pass solution is based on Dutch National Flag Algorithm
    // arr[0] to arr[lo – 1]: This part will have all the zeros.
    // arr[lo] to arr[mid – 1]: This part will have all the ones.
    // arr[hi + 1] to arr[n – 1]: This part will have all the twos.
    
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int l=0,mid=0,h=n-1;
        while(mid<=h)
        {
            if(nums[mid]==0) swap(nums[l++],nums[mid++]);
            else if(nums[mid]==1) mid++;
            else swap(nums[h--],nums[mid]);
        }
    }
};