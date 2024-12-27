class Solution {
public:
    // we need to get the maximum of this value (values[i]+values[j]+i-j) , It can be treated as one entity for each of the index. 
    // we need to keep track of two values for each of the index. i.e., (values[i]+i), (values[j]-j) and for each 'i' look on the right
    // side having the maximum value present of (values[j]-j)
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        vector<int>val_with_i(n);
        vector<int>val_with_j(n);
        int ans=0;
        for(int i=0;i<n;++i)
        {
            val_with_i[i]=(values[i]+i);
            val_with_j[i]=(values[i]-i);
        }

        int mxm_reverse=val_with_j[n-1];
        for(int i=n-2;i>=0;--i)
        {
            int curr=val_with_i[i]+mxm_reverse;   // Treating each of the index as the potential answer.
            ans=max(ans,curr);
            mxm_reverse=max(mxm_reverse,val_with_j[i]);
        }
        return ans;
    }
};