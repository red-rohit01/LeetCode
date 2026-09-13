class Solution {
public:
    vector<pair<int,int>> onescell(vector<vector<int>>img)
    {
        vector<pair<int,int>>ans;
        int m=img.size();
        int n=img[0].size();
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(img[i][j]==1)
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>>ones1=onescell(img1);
        vector<pair<int,int>>ones2=onescell(img2);
        
        int ans=0;
        map<pair<int,int>,int>mp;
        for(auto [i1,j1]:ones1)
        {
            for(auto [i2,j2]:ones2)
            {
                mp[{i1-i2,j1-j2}]++;
                ans=max(ans,mp[{i1-i2,j1-j2}]);
            }
        }
        return ans;
        
    }
};