class Solution {
public:
    // The idea is simple that in all of the broken subarrays the difference between max_element and first position element should
    // be equal to the size of the subarray under consideration which can be find by the size of the set.
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int first=0;
        int ans=0;
        set<int>st;
        for(int i=0;i<n;++i)
        {
            st.insert(arr[i]);
            int sz=st.size();

            int last=*(--st.end());
            if((last-first+1)==sz)
            {
                ans++;
                first=last+1;   // update the first as in next chunk this will be the first(or lowest) element required.
                st.clear();
            }
        }

        return ans;
    }
};