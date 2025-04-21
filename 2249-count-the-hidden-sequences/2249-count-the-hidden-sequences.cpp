class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n=differences.size();
        int mx=upper-lower;
        for(auto &x:differences)
        {
            if(abs(x)>mx) return 0;
        }
    
        for(int prev=lower;prev<=upper;++prev)
        {
            int val=prev;
            int i=0;
            int mxm=prev;
            for(;i<n;++i)
            {
                int nxt=val+differences[i];
                if(nxt>upper || nxt<lower) break;

                val=nxt;
                mxm=max(mxm,nxt);
            }
            if(i==n)
            {
                int ans=(upper-mxm+1);
                return ans;
            }
        }
        return 0;
    }
};