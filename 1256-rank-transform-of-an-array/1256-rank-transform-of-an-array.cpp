class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans=arr;
        sort(ans.begin(),ans.end());
        int rank=1;
        map<int,int>rk;
        for(int i=0;i<n;++i)
        {
            rk[ans[i]]=rank;
            int j=i+1;
            while(j<n && ans[j]==ans[j-1]) j++;

            rank++;
            i=j-1;
        }

        for(int i=0;i<n;++i) ans[i]=rk[arr[i]];
        
        return ans;
    }
};