class Solution {
public:
    // The idea is simple that since At any time It's possible to get the new minimum value for any particular grid and we are allowed
    // to move in any of the four directions. so, It's a graph based problem for BFS and not only DP
    // Similar to LC: 2290
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size();
        int m=moveTime[0].size();

        vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
        ans[0][0]=0;

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,0,0});
        vector<int>dr={-1,0,1,0,-1};

        while(!pq.empty())
        {
            auto temp=pq.top();
            pq.pop();

            int time=temp[0];
            int row=temp[1];
            int col=temp[2];
            
            if(time>ans[row][col]) continue;   // We already got a lower value for this particular grid so, can ignore this 

            if(row==n-1 && col==m-1) return ans[row][col];

            for(int k=0;k<4;++k) 
            {
                int nrow=row+dr[k];
                int ncol=col+dr[k+1];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]==INT_MAX)
                {
                    int cost=(row+col)%2 +1;
                    ans[nrow][ncol]=max(time,moveTime[nrow][ncol])+cost;
                    pq.push({ans[nrow][ncol],nrow,ncol});
                }
            }
        }
        return ans[n-1][m-1];
    }
};