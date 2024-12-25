class Solution {
public:
    // TC: O(N*2^N)
    int ans=1e9;
    void helper(vector<int>& s, int mask, int x, int k, int temp) 
    {
        int n=s.size();
        if(mask==(1<<n)-1) 
        {
            ans=min(ans,temp);
            return;
        }
        int sum=x,add=0;
        for(int i=0;i<n;++i) 
        {
            if(mask & (1<<i)) continue;

            add=(s[i]+x-1)/x;
            helper(s, mask|(1<<i),x+k,k,temp+add);
        }
    }
    int findMinimumTime(vector<int>& strength, int k) {
        helper(strength,0,1,k,0);
        return ans;
    }
};