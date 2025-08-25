class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        vector<int>ans;
        int i=0,j=0;
        int cnt=0;
        bool flag=true;
        while(cnt<(m*n))
        {
            if(flag)
            {
                while(i>=0 && j<n && cnt<(m*n))
                {
                    ans.push_back(mat[i][j]);
                    cnt++;
                    i--;
                    j++;
                }
                if(j<n) i=0;
                else
                {
                    i+=2;
                    j--;
                }
            }
            else 
            {
                while(i<m && j>=0 && cnt<(m*n))
                {
                    ans.push_back(mat[i][j]);
                    cnt++;
                    i++;
                    j--;
                }
                if(i<m) j++;
                else
                {
                    i=m-1;
                    j+=2;
                }
            }
            flag=!flag;
        }
        return ans;
    }
};