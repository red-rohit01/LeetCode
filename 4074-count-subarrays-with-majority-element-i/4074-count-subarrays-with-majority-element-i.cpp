class Solution {
public:
    // target --> +1
    // others --> -1
    // Now in any subarray:
    // sum = (#target) - (#non-target)
    // for target to be majority: #target > #non-target == sum>0
    // we build prefix sums. If pref[i]>pref[j]  then subarray (j+1 ....i) has positive sum.
    // so the problem becomes "counting how many previous prefix sums are smaller than the current prefix sum"
    // freq[x]== how many times a prefix sum 'x' appeared.

    // Since the prefix changes by only +1 or −1:
    // If the prefix increases, only the previous prefixes equal to the old balance become newly smaller, so add their frequency to less.
    // If the prefix decreases, the previous prefixes equal to the new balance are no longer smaller, so subtract their frequency from less.
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();

        vector<int>freq(2*n+1);   // Here size is (2*n +1) because maximum value can go till 'n' and minimum can '-n'. so, to represent '-n' also we are using the shift value equal to 'n'.
        int shiftValue=n;
        freq[n]=1;            // 'n' actually means prefix sum ==0

        long long lessCount=0;   // number of previous prefixSums which are smaller than the current prefixSum (i.e., lastSum)
        long long ans=0;
        long long lastSum=0;   // actually storing the prefix sum
        for(int x:nums) 
        {
            if(x==target) 
            {
                lessCount+=freq[lastSum + shiftValue];

                lastSum++;
                freq[lastSum + shiftValue]++;
            } 
            else 
            {
                lastSum--;

                lessCount-=freq[lastSum + shiftValue];
                ++freq[lastSum + shiftValue];
            }
            ans+=lessCount;
        }
        return ans;
    }
};