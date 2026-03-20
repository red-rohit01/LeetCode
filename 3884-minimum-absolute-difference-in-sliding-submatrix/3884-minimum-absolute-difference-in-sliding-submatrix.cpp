class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>ans(n-k+1,vector<int>(m-k+1));
        for(int i=0;i<=(n-k);++i)
        {
            map<int,int>mp;
            for(int r=i;r<(i+k);++r)
            {
                for(int c=0;c<k;++c) mp[grid[r][c]]++;
            }

            for(int c=0;c<=(m-k);++c)
            {
                if(mp.size()>1)
                {
                    int mn=1e9;

                    auto it=mp.begin();
                    int prev=it->first;

                    for(++it;it!=mp.end();it++)
                    {
                        mn=min(mn,(it->first-prev));
                        prev=it->first;
                    }

                    ans[i][c]=mn;
                }
                else ans[i][c]=0;

                if(c<(m-k))
                {
                    for(int r=i;r<(i+k);++r)
                    {
                        if(--mp[grid[r][c]]==0) mp.erase(grid[r][c]);

                        mp[grid[r][c+k]]++;
                    }
                }
            }
        }

        return ans;
    }
};