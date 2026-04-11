class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        vector<array<int,2>>V(n+1,{-1,-1});

        int ans=1e9;
        for(int i=0;i<n;++i) 
        {
            int x=nums[i];

            if(V[x][0]==-1) V[x][0]=i;
            else if(V[x][1]==-1) V[x][1]=i;
            else 
            {
                // Directly using derived formula
                ans=min(ans,2*(i-V[x][0]));

                // shift window
                V[x][0]=V[x][1];
                V[x][1]=i;
            }
        }

        return (ans==1e9)?-1:ans;
    }
};