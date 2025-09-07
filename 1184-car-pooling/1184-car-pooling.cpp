class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size();
        vector<int>road(1005);
        for(int i=0;i<n;++i)
        {
            int pass=trips[i][0];
            int from=trips[i][1];
            int to=trips[i][2];

            road[from]+=pass;
            road[to]-=pass;
        }

        int curr=0;
        for(int i=0;i<=1000;++i)
        {
            curr+=road[i];
            if(curr>capacity) return false;
        }
        return true;
    }
};