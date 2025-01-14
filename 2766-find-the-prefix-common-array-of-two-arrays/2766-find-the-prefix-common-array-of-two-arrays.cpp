class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>ans(n),rk(51);

        for(int i=0;i<n;++i)
        {
            ans[i]=((++rk[A[i]]==2) + (++rk[B[i]]==2));
        }
        for(int i=1;i<n;++i) ans[i]+=ans[i-1];

        return ans;
    }
};