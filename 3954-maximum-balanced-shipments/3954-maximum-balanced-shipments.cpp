class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n=weight.size();
        int ans=0;
        int mx=-1;
        for(int i=0;i<n;++i)
        {
            mx=max(mx,weight[i]);
            if(weight[i]<mx)
            {
                ans++;
                mx=-1;
            }
        }
        return ans;
    }
};