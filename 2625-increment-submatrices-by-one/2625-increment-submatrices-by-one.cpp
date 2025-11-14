class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>val(n,vector<int>(n));
        for(int i=0;i<queries.size();++i)
        {
            int row1=queries[i][0];
            int col1=queries[i][1];
            int row2=queries[i][2];
            int col2=queries[i][3];
            
            val[row1][col1]+=1;
            if (row2+1<n && col2+1<n) val[row2+1][col2+1]++;
            
            if (row2 + 1 < n) val[row2 + 1][col1]--;
            
            if (col2 + 1 < n) val[row1][col2 + 1]--;
        }
        
        
        for(int i=0;i<n;++i) 
        {
            for(int j=1;j<n;++j) 
            {
                val[i][j]+=val[i][j-1];
            }
        }
        for(int i=1;i<n;++i) 
        {
            for(int j=0;j<n;++j) 
            {
                val[i][j]+=val[i-1][j];
            }
        }
        vector<vector<int>>ans(n,vector<int>(n));
        for(int i=0;i<n;++i) 
        {
            for(int j=0;j<n;++j) 
            {
                ans[i][j]=val[i][j];
            }
        }
        return ans;
    }
};