class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans=0;
        int prev_diag=0;
        for(auto &x:dimensions)
        {
            int len=x[0];
            int brd=x[1];

            int curr_diag=(len*len)+(brd*brd);
            if(curr_diag>prev_diag)
            {
                int curr_area=len*brd;
                prev_diag=curr_diag;
                ans=curr_area;
            }
            else if(curr_diag>=prev_diag) 
            {
                ans=max(ans,len*brd);
            }
        }
        return ans;
    }
};