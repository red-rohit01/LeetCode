class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
        bool ans=false;
        for(int i=0;i<n;++i)
        {
            if(i==n-1) ans=true;
            if(bits[i]==1) i++;
        }
        return ans;
    }
};