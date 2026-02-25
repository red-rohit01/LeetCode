class Solution {
public:
    static bool comp(int a,int b)
    {
        int p=__builtin_popcount(a);
        int q=__builtin_popcount(b);
        if(p==q)
        {
            return a<b;
        }
        return p<q;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comp);
        return arr;
    }
};