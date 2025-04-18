class Solution {
public:
    // This is O(n^2) solution. There is a better solution with O(n)
    // On Observation:
    //              |0C0|
    //            |1C0||1C1|
    //          |2C0||2C1||2C2|
    //         |3C0||3C1||3C2||3C3|
    //       |4C0||4C1||4C2||4C3||4C4|
    // So, simply build the n'th row
    vector<int> getRow(int rowIndex) {
        // vector<int>ans(rowIndex+1);
        // ans[0]=1;
        // for(int i=1;i<=rowIndex;++i)
        // {
        //     for(int j=i;j>=1;--j) ans[j]+=ans[j-1];
        // }
        // return ans;

        long long prev=1;
        vector<int>ans;
        ans.push_back(prev);
        long long n=1LL*rowIndex;
        for(int i=1;i<=rowIndex;++i)
        {
            long long curr=(prev*(n-i+1))/i;
            ans.push_back(curr);
            prev=curr;
        }
        return ans;
    }
};