class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int>next(n);
        for(int j=0;j<n;++j)
        {
            next[j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;--i)
        {
            vector<int>curr(i+1);
            for(int j=0;j<=i;j++)
            {
                curr[j]=min(next[j],next[j+1])+triangle[i][j];
            }
            next=curr;
        }
        return next[0];
    }
};