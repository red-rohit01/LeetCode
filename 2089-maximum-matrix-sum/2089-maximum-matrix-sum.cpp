class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        long long sum=0;
        int cnt=0;
        int mn=INT_MAX;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(matrix[i][j]<=0)
                {
                    mn=min(mn,-1*matrix[i][j]);
                    cnt++;
                    sum+=1LL*(-1*matrix[i][j]);
                }
                else 
                {
                    sum+=1LL*matrix[i][j];
                    mn=min(mn,matrix[i][j]);
                }    
            }
        }

        if(cnt%2==0) return sum;

        return (sum-1LL*2*mn);   // Sum is having the entire matrix sum. so, subtract the sum with (2*lowest_value)
    }
};