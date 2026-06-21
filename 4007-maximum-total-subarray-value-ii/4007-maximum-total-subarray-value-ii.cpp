class Solution {
public:
    // 1. The Core Trick: The Snowball Effect
    // If you pick a fixed starting point l for a subarray and expand your window by moving r to the right, two things happen:

    // The maximum element can only grow or stay the same (as you invite new elements in).
    // The minimum element can only shrink or stay the same.
    // Because Value = Max - Min, as the window expands, the value can never decrease. It either goes up or stays the same.

    // Build a Sparse Table for range maximum queries.
    // Build another Sparse Table for range minimum queries.
    // Create a function that returns: max(nums[l...r]) - min(nums[l...r])

    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int>lg(n+1);      // lg[x]=⌊log2​(x)⌋   --> floor value
        for (int i=2;i<=n;++i) lg[i]=lg[i/2]+1;

        int K=lg[n]+1;

        vector<vector<int>> mx(K, vector<int>(n));    // mx[j][i]--> stores the maximum in a segment of length 2^j starting at i or it stores the maximum in the range [i,i+2^j−1]
        vector<vector<int>> mn(K, vector<int>(n));    // mn[j][i]--> stores the minimum in a segment of length 2^j starting at i or it stores the minimum in the range [i, i+2^j-1]

        for(int i=0;i<n;++i) 
        {
            mx[0][i]=nums[i];
            mn[0][i]=nums[i];
        }

        // Suppose we want the maximum in an interval of length 2^j. Then split it into two halves of length 2^(j-1)
        // Actually, i+(1<<(j-1)) is the start of the second half.
        for(int j=1;j<K;j++) 
        {
            for(int i=0;i+(1<<j)<=n;++i) 
            {
                mx[j][i]=max(mx[j-1][i],mx[j-1][i+(1<<(j-1))]);

                mn[j][i]=min(mn[j-1][i],mn[j-1][i+(1<<(j-1))]);
            }
        }

        auto getValue = [&](int l, int r) -> long long 
        {
            // For any interval of length 'len' 
            // let blocklength= 2^p
            // where 2^p is the largest power of two not exceeding the interval length.

            // Left block:
            // [l ............ l+2^p-1]

            // Right block:
            // [r-2^p+1 ..... r]

            // These two blocks may overlap but it's completely fine
            // for e.g., [4,2,5]
            // while calculating the maximum we'll have max(mx[1][0], mx[1][1]) == max (max{4,2}, max{2,5}) == max(4,5)==5
            int len=r-l+1;
            int p=lg[len];

            int mxVal=max(mx[p][l],mx[p][r - (1<<p)+1]);  // l and forward to first half and from 'r' backward till the second half

            int mnVal=min(mn[p][l],mn[p][r - (1<<p)+1]);

            return 1LL * mxVal - mnVal;
        };

        struct Node 
        {
            long long val;
            int l;
            int r;

            bool operator<(const Node& other) const {
                return val < other.val;
            }
        };

        priority_queue<Node> pq;

        for(int l=0;l<n;++l) 
        {
            pq.push({getValue(l, n - 1), l, n - 1});
        }

        long long ans=0;

        while(k--) 
        {
            auto cur=pq.top();
            pq.pop();

            ans+=cur.val;

            if (cur.r>cur.l)   // If the popped state is (l,r) then the next candidate from the same sequence is (l, r-1)
            {
                pq.push({getValue(cur.l, cur.r - 1),cur.l,cur.r - 1});
            }
        }
        return ans;
    }

    // TC: O(nlogn) + O(klogn)
};