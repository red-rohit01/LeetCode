class Solution {
public:
    // See A very Nice Dry Run here: https://leetcode.com/problems/maximize-subarrays-after-removing-one-conflicting-pair/solutions/7005474/maximize-subarrays-a-single-pass-o-n-solution-python-c-java/
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<long long>>right(n+1);    // right[v]--> stores all starting points 'u' that form a pair (u,v)
        for(auto &p:conflictingPairs)
        {
            right[max(p[0],p[1])].push_back(min(p[0],p[1]));
        }

        long long ans=0;     // stores the total count of valid subarrays with all conflicts present (base score)
        vector<long long>left={0,0};          //{higher_val, lower_val}  // It stores top2 forbidden starts
        vector<long long>bonus(n+1);      // It stores the total potential gain if the critical conflict starting at 'i' is removed.

        for(int r=1;r<=n;++r)
        {
            for(auto &u:right[r])
            {
                //Manually update the top two values
                if(u>left[0]) left={u,left[0]};
                else if(u>left[1]) left={left[0],u};
            }

            ans+=(r-left[0]);

            if(left[0]>0) bonus[left[0]]+=(left[0]-left[1]);
        }

        long long mx=0;
        for(auto &x:bonus) mx=max(mx,x);

        return (ans+mx);
    }
};