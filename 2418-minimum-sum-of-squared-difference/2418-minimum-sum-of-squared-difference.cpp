class Solution {
public: 
    // Every +1/-1 on nums1 or nums2 shrinks one difference by exactly 1 --> so, k1 and k2 becomes one shared budget.
    // Go from i = max down to 1 while k > 0:
    // move = min(k, d[i]) → how many positions at level i we can lower
    // they all go down one level: d[i]-=move, d[i-1]+=move     e.g., if we have two blocks having diff==4 and k=5, then if we decrease these two blocks, then for those two blocks diff now =3, k=3(5-2) so, d[4-1] increases by number of moves performed.
    // spend the budget: k -= move
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int>d(100001);
        long long k=(long long)k1+k2, sum=0;
        int mx=0, n=nums1.size();

        // Step 1: count the differences
        for(int i=0;i<n;++i) 
        {
            int x=abs(nums1[i]-nums2[i]);
            d[x]++;
            sum+=x;
            mx=max(mx,x);
        }
        // Enough budget->every difference becomes 0
        if (sum<=k) return 0;

        // Step 2: shave the biggest differences, level by level
        for(int i=mx;i>0 && k>0;--i) 
        {
            long long move=min(k,(long long)d[i]);
            d[i]-=move;
            d[i-1]+=move;
            k-=move;
        }

        long long ans=0;
        for(int i=0;i<=mx;++i) ans+=(long long)i*i*d[i];

        return ans;
    }
};