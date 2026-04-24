class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n=moves.size();
        int cnt=0;
        int ans=0;
        for(int i=0;i<n;++i)
        {
            if(moves[i]=='R')ans++;
            else if(moves[i]=='L') ans--;
            else cnt++;
        }
        if(ans>=0) (ans+=cnt);
        else ans=(cnt-ans);
        return ans;
    }
};