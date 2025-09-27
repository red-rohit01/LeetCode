class Solution {
public:
    // 1/2(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))
    double largestTriangleArea(vector<vector<int>>& points) {
        double res = 0;
        for (auto &i : points)
        {
            int x1=i[0];
            int y1=i[1];
            for (auto &j : points)
            {
                int x2=j[0];
                int y2=j[1];
                
                for(auto &k:points)
                {
                    int x3=k[0];
                    int y3=k[1];
                    res = max(res ,abs(0.5*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))));
                }
            }
        }
        return res;
    }
};