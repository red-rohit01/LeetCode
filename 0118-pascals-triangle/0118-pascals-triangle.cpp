class Solution {
public:
    void helper(vector<vector<int>>&ans,int n)
    {
        vector<int>prev(1,1);
        ans.push_back(prev);
        for(int i=2;i<=n;i++)
        {
            vector<int>curr;
            curr.push_back(1);
            int t=0;
            for(int j=2;j<i;j++)
            {
                int num=prev[t]+prev[t+1];
                t++;
                curr.push_back(num);
            }
            curr.push_back(1);
            ans.push_back(curr);
            prev=curr;
        }
        
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        helper(ans,numRows);
        return ans;
    }
};