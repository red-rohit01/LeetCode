class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        if(n<3 || m<3) return 0;
        int ans=0;
        for(int i=0;i<=(n-3);++i)
        {
            for(int j=0;j<=(m-3);++j)
            {
                set<int>st;
                set<int>val;
                for(int l=i;l<(i+3);++l)
                {
                    int sm=0;
                    for(int m=j;m<(j+3);++m)
                    {
                        sm+=grid[l][m];
                        if(grid[l][m]<=9 && grid[l][m]>=1) val.insert(grid[l][m]);
                    }
                    st.insert(sm);
                }

                if(val.size()!=9) continue;     // Leave this Particular Matrix

                for(int m=j;m<(j+3);++m)
                {
                    int sm=0;
                    for(int l=i;l<(i+3);++l) sm+=grid[l][m];

                    st.insert(sm);
                }

                int diag1=grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
                st.insert(diag1);

                int diag2=grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j];
                st.insert(diag2);

                if(st.size()==1) ans++;
            }
        }
        return ans;
    }
};