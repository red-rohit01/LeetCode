class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        int n=points.size();
        int currx=points[0][0];
        int curry=points[0][1];
        for(int i=1;i<n;++i)
        {
            int val1=abs(points[i][0]-currx);
            int val2=abs(points[i][1]-curry);

            ans+=max(val1,val2);
            currx=points[i][0];
            curry=points[i][1];
        }
        return ans;
    }
};