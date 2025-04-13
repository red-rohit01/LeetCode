class Solution {
public:
    // Swapping 2 elements can be thought of as swapping both of the elements to position 0 and then swapping them back to the desired position
    // Lets call an index bad is nums1[index] = nums2[index]. Imagine this, you collect all "bad indexes" in the 0th index. The cost to move this index to the 0th index is the index of the element.
    // Now, you can use these collected indexes and distribute them to the desired positions. (note that we don't have to add any extra cost here, we can assume that once an element has come to position 0, it is free to move)
    // The only thing to care is the case where the maximum occuring element occurs more than half the values. In this case we need to collect more indexes even though they aren't "bad".
    // e.g., nums1: [2, 2, 2, 3, 3]
    //       nums2: [3, 2, 2, 3, 1]
    // If we only consider bad indices(along with 0 index) to be distrubuted i.e. 0, 1, 2, 3, then we can not distrubute the elements to create unequal array, but if we take index 4 as well, then it is possible to get an unequal array configuration.
    
    // We want to collect indexes which contribute less cost, i.e which occur earlier (smallest index) as well as taking care that the value doesn't equal to the max occuring element (worsening our situation) and also ensuring that nums2[index] != max occurent element
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        long long ans=0;
        map<int,int>freq;

        int mx_freq=0,mx_val=0, swap=0;

        for(int i=0;i<n;++i)
        {
            if(nums1[i]==nums2[i])
            {
                freq[nums1[i]]++;
                if(freq[nums1[i]]>mx_freq) 
                {
                    mx_val=nums1[i];
                    mx_freq=freq[nums1[i]];
                }
                swap++;
                ans+=i;
            }
        }


        for(int i=0;i<n;++i)
        {
            if(mx_freq>(swap/2) && nums1[i]!=nums2[i] && nums1[i]!=mx_val && nums2[i]!=mx_val)
            {
                ans+=i;
                swap++;
            }
        }

        if(mx_freq>(swap/2)) return -1;

        return ans;
    }
};