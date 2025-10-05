class Solution {
public:
    int largest_rectangle(vector<int>&x)
    {
        int m=x.size();
        stack<int>st;
        int mx=0;

        for(int j=0;j<=m;++j)
        {
            while(!st.empty() && (j==m || x[st.top()]>x[j]))
            {
                int ht=x[st.top()];
                st.pop();
                int wd=j;
                if(!st.empty()) wd=j-st.top()-1;      // consideration of width is the position one less than where I'm currently

                mx=max(mx,ht*wd);
                // if(j==m) cout<<ht<<" "<<wd<<"\n";
            }
            st.push(j);
        }
        return mx;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        // int n=matrix.size();
        // int m=matrix[0].size();
        // vector<vector<int>>rk(n,vector<int>(m));  // Height of the bar
        // for(int i=0;i<n;++i)
        // {
        //     for(int j=0;j<m;++j)
        //     {
        //         rk[i][j]=(matrix[i][j]-'0');
        //         if(rk[i][j]>0 && i>0) rk[i][j]+=rk[i-1][j];
        //     }    
        // }

        // int ans=0;
        // for(auto &x:rk) ans=max(ans,largest_rectangle(x));

        // return ans;

        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>left(n);//left[i]=j-->Tells us the left most index 'j' which satisfies for k=[j,i](k belongs to index from j to i) and height[k]>=height[i]
        vector<int>right(n,n-1); //right[i]=j --> Tells us the right most index 'j' which satisfies for k=[i,j] and height[k]>=height[i]
        vector<int>height(n);
        int maxArea=0;

        for(const auto& row : matrix) 
        {
            int curLeft=0,curRight=n-1;   // curr_row_left_Boundary and curr_row_right_Boundary
            for(int j=0;j<n;++j) 
            {
                if (row[j]=='1') height[j]++;
                else height[j]=0;
            }

            for(int j=0;j<n;++j) 
            {
                if(row[j]=='1') left[j]=max(left[j], curLeft);
                else 
                {
                    left[j]=0;
                    curLeft=j+1;   //Only (j+1)'th index or higher can be our boundary for further values.
                }
            }

            for(int j=n-1;j>=0;--j) 
            {
                if(row[j]=='1') right[j] = min(right[j], curRight);
                else 
                {
                    right[j]=n-1;
                    curRight=j-1;
                }
            }

            for (int j=0;j<n;++j) 
            {
                //cout<<left[j]<<" "<<right[j]<<" - ";
                maxArea=max(maxArea, (right[j]-left[j]+1)*height[j]);
            }
            //cout<<"\n";
        }
        return maxArea;
    }
};