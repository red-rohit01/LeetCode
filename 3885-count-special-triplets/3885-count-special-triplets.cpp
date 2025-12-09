class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int mod=1e9+7,res=0;
        unordered_map<int, int>left,right;

        for (int &x:nums) right[x]++;

        for(int &x:nums) 
        {
            right[x]--;
            res=(res+1LL*left[x*2]*right[x*2])%mod;
            left[x]++;
        }
        return res;
    }
};