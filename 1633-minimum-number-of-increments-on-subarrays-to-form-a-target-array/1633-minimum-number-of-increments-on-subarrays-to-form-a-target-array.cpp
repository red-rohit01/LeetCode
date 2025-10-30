class Solution {
public:
    // Sample Example 2: [3,1,1,2] clearly explains the below implementation
    // Reason is that it's always possible to make a subarray starting at index 'i' to create if all the upcoming elements are <=target[i]
    int minNumberOperations(vector<int>& target) {
        int ans=target[0];
        int n=target.size();
        for(int i=1;i<n;++i)
        {
            ans+=max(target[i]-target[i-1],0);
        }
        return ans;
    }
};