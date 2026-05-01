class Solution {
public:
    // R0 = 0*arr[0] + 1*arr[1] +...+ (n-1)*arr[n-1]

    // After 1 rotation arr[n-1], becomes first element of array, 

    // arr[0] becomes second element, arr[1] becomes third element and so on.
    // R1 = 0*arr[n-1] + 1*arr[0] +...+ (n-1)*arr[n-2]
    // R1 - R0 = arr[0] + arr[1] + ... + arr[n-2] - (n-1)*arr[n-1]
    // After 2 rotations arr[n-2], becomes first element of array, 

    // arr[n-1] becomes second element, arr[0] becomes third element and so on.
    // R2 = 0*arr[n-2] + 1*arr[n-1] +...+ (n-1)*arr[n-3]
    // R2 - R1 = arr[0] + arr[1] + ... + arr[n-3] - (n-1)*arr[n-2] + arr[n-1]
    // If we take a closer look at above values, we can observe below pattern:

    // Rj - Rj-1 = totalSum - n * arr[n-j]

    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        int prev=0;
        for(int i=0;i<n;++i)
        {
            total+=nums[i];
            prev+=(i*nums[i]);
        }

        int ans=prev;

        for(int i=1;i<n;++i)
        {
            int curr=prev+(total-n*nums[n-i]);
            ans=max(ans,curr);
            prev=curr;
        }
        return ans;
    }
};