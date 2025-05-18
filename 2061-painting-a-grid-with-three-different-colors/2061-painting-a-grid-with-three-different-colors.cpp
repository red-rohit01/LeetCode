class Solution {
public:
    // The idea is that since 'row' value is small.so, we can try out all the possibilities of arrangements in the first column and then
    // corresponding valid arrangements in the second column and so on.
    // Total number of valid arrangements in the first column == 3x3x3....m ==3^m and 3^5=243
    // Nice explanation by Coding Grower(YT) 
    // Check and keep track of which of the two neighboring configurations are not valid in rowValid.
    const int mod=1e9+7;
    int colorTheGrid(int m, int n) {
        int total=(int)pow(3,m);
        vector<int>good, pattern[250];

        vector<vector<int>>dp(n+1,vector<int>(total+1));
        //int rowvalid[total+1][total+1];  // It'll give error as n and total are not compile-time constants.C++ does not support variable length arrays

        vector<vector<int>>rowvalid(total+1,vector<int>(total+1));

        for(int i=0;i<total;++i)
        {
            int val=i;
            bool flag=true;
            for(int row=0;row<m;++row)
            {
                pattern[i].push_back(val%3);
                val/=3;
            }

            for(int row=1;row<m;++row)
            {
                if(pattern[i][row]==pattern[i][row-1]) 
                {
                    flag=false;
                    break;
                }
            }
            if(flag) good.push_back(i);
        }

        // Now we got all the good candidates. so, the Task is to check the validity row-wise of whether two column configurations would be 
        // valid or not

        for(auto &x:good)
        {
            for(auto &y:good)
            {
                rowvalid[x][y]=1;
                for(int row=0;row<m;++row) 
                {
                    if(pattern[x][row]==pattern[y][row]) 
                    {
                        rowvalid[x][y]=0;
                        break;
                    }
                }
            }
        }

        for(auto &x:good) dp[1][x]=1;
        for(int col=2;col<=n;++col)
        {
            for(auto &x:good)
            {
                for(auto &y:good)
                {
                    if(rowvalid[x][y])
                    {
                        dp[col][x]=(dp[col][x]%mod + dp[col-1][y]%mod)%mod;  // 'x' is used on current col and 'y' on the previous one
                    }
                }
            }
        }

        int ans=0;
        for(int i=0;i<total;++i)
        {
            ans=(ans%mod + dp[n][i]%mod)%mod;
        }
        return ans;
    }
};