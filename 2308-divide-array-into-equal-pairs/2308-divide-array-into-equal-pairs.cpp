class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int,int>freq;
        for(auto &x:nums) freq[x]++;

        for(auto &x:freq)
        {
            if(x.second%2) return false;
        }
        return true;
    }
};