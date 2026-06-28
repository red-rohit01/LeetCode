class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int prev=1;
        int ans=1;
        for(int i=1;i<n;++i)
        {
            if(arr[i]<=(1+prev))
            {
                prev=arr[i];
            }
            else prev++;
            
            ans=prev;
        }
        return ans;
    }
};