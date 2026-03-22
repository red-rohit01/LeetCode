class Solution {
public:
    // 90 degree clockwise rotation:
    // (1) First Take the Transpose
    // (2) Reverse Each Row

    // 90 degree Anti-clockwise rotation:
    // (1) Reverse Each Row 
    // (2) Take Transpose of this reversed matrix
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();
        for(int cnt=0;cnt<4;++cnt)
        {
            // Taking Transpose
            for(int i=0;i<n;++i)
            {
                for(int j=i+1;j<n;++j) swap(mat[i][j],mat[j][i]);
            }

            // Reverse each row
            for(int i=0;i<n;++i) reverse(mat[i].begin(),mat[i].end());

            if(mat==target) return true;

            // for(int i=0;i<n;++i)
            // {
            //     for(int j=0;j<n;++j) cout<<mat[i][j]<<" ";
            //     cout<<"\n";
            // }

            // cout<<"---------------------\n";
        }
        return false;
    }
};