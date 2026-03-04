class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int> rows(n),cols(m);
        for (int i=0;i<n;++i)
        {
            for (int j=0;j<m;++j) 
            {
                if (mat[i][j]) ++rows[i], ++cols[j];
            }
        }
        
    int res = 0;
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            if (mat[i][j] && rows[i] == 1 && cols[j] == 1) ++res;

        return res;
    }
};