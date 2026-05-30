class Solution {
public:
    int mxVal = 50000;
    vector<int> tree;

    // Segment Tree: Update value at a specific index
    void update(int node, int start, int end, int idx, int val) 
    {
        if (start == end) {
            tree[node] = val;
            return;
        }

        int mid = start + (end - start) / 2;

        if (idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);

        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    // Segment Tree: Query max value in range [l, r]
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return 0;

        if (l <= start && end <= r)
            return tree[node];

        int mid = start + (end - start) / 2;

        int leftMax = query(2 * node, start, mid, l, r);
        int rightMax = query(2 * node + 1, mid + 1, end, l, r);

        return max(leftMax, rightMax);
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        tree.resize(4*(mxVal + 1), 0);
        vector<bool>results;
        set<int>obstacles;

        obstacles.insert(0);
        obstacles.insert(mxVal);

        update(1, 0, mxVal, mxVal, mxVal);

        for (auto& q : queries) 
        {
            int type = q[0];

            if (type == 1) 
            {
                int x = q[1];

                // Find adjacent obstacles
                auto itNext = obstacles.lower_bound(x);
                int next = *itNext;

                int prev = *(--obstacles.lower_bound(x));

                // Add new obstacle
                obstacles.insert(x);

                // Update segments in Segment Tree
                update(1, 0, mxVal, x, x - prev);
                update(1, 0, mxVal, next, next - x);
            }
            else if (type == 2) 
            {
                int x = q[1];
                int sz = q[2];

                int prev = *(--obstacles.upper_bound(x));

                int maxGapInSegmentTree = query(1, 0, mxVal, 0, prev);
                int lastGap = x - prev;

                int maxAvailableGap = max(maxGapInSegmentTree, lastGap);

                results.push_back(maxAvailableGap >= sz);
            }
        }
        return results;
    }
};