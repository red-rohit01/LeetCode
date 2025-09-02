class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end(),[&](auto &p1,auto &p2)
        {
            if(p1[0]==p2[0]) return p1[1]>p2[1];

            return p1[0]<p2[0];
        });

        int ans=0;

        // Considering 'i' as the upper left point 'A' and 'j' as the lower right point 'B'.
        // Here 'y' is working as the indicator that there is no point inside the rectangle being formed
        for(int i=0;i<n;++i)
        {
            for(int j=i+1,y=-1;j<n;++j)
            {
                if(points[i][1]>=points[j][1] && y<points[j][1])
                {
                    ans++;
                    y=points[j][1];
                }
            }
        }
        return ans;
    }
};