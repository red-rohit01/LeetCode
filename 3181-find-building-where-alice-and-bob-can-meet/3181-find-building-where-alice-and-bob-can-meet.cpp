class Solution {
public:
    // Normal MonoStack would fail for this below TC. When both ngr[a] and ngr[b] can't be answer. 
    // e.g., [3,4,1,2,5] and q==[0,1]

    int binarySearch(int height, vector<pair<int, int>>&st) 
    {
        int l=0, r=st.size()-1;
        int ans=-1;
        while (l<=r) 
        {
            int mid=l+(r-l)/2;
            if (st[mid].first>height)   // for finding greater than 6, The array would be [11,10,8,7,5,3,2] Thus even if we got our
            {                           // ans we need to do l=mid+1
                ans=mid;
                l=mid+1;
            } 
            else 
            {
                r=mid-1;
            }
        }
        return ans;
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n=heights.size();
        int q_len=queries.size();
        vector<int>ans(q_len,-1);
        vector<vector<pair<int,int>>>idx(n); // Here we thought of pushing for each of the queries end index {height and query_no}
        // like [{8,i5}, {11,i5}]  It means ending at index 5, one of the query is find height greater than '8' and another query
        // is to find height greater than '11'.
        
        for(int i=0;i<q_len;++i)
        {
            int a=queries[i][0];
            int b=queries[i][1];

            if(a>b) swap(a,b);

            if(heights[b]>heights[a] || (a==b)) 
            {
                ans[i]=b;
            }
            else idx[b].push_back({heights[a],i});
        }

        vector<pair<int,int>>st;  // Monotonically decreasing stack so can apply Binary search on it.
        for(int i=n-1;i>=0;--i)
        {
            for (auto &[ht,ind]:idx[i]) 
            {
                int pos=binarySearch(ht, st);
                if (pos!=-1) ans[ind]=st[pos].second;
            }
            while(!st.empty() && st.back().first <= heights[i]) st.pop_back();

            st.push_back({heights[i], i});
        }
        return ans;
    }
};