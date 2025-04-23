class Solution {
public:
    // Since, we need to report any of the peak element...then why don't we try to convert this 2-D problem to 1-D Peak element problem.
    // Let's create a vector of maximum element from each of the columns e.g., [21,30,32] (Example 2) and then find the Peak.
    // If we find a peak plane at index 'p', then it means that there is an element in column# p which is bigger than all the elments 
    // in column# p-1 and column# p+1. Once we have the peak column p, we can easily find the row# of the peak element in the column# p. 
    // Now you have both row# and col# of a peak element in 2D array. Thats it !!

    // BUT!! BUT!! BUT!!

    // To populate maxPlaneOfCol[N], we need to traverse all the columns in the 2D array, which basically means that we have to read all 
    // the elements in 2D array. So, when you are reading the entire 2D array, why not just return the coordinates of the largest number 
    // in the 2D array ?!! The largest element is gauranteed to be a peak element, isn't it !!??

    // HOLD ON \U0001f914\U0001f914\U0001f914

    // Do we really need to find the max in each and every column? Will it not be sufficent to just find the max of the midColumn? 
    // If we find the max of only the midColumn, we will calculate max of only log(N) columns in our entire algorithm.
    // Hence the Time Complexity is M*log(N).
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        int l=0,h=n-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;

            int mx_val=mat[0][mid];
            int row=0;
            for(int i=1;i<m;++i)
            {
                if(mat[i][mid]>mx_val)
                {
                    mx_val=mat[i][mid];
                    row=i;
                }
            }

            bool left_candidate=((mid-1)>=l && mx_val<mat[row][mid-1]);    // checking if 'left' side is a valid candidate for peak
            bool right_candidate=((mid+1)<=h && mx_val<mat[row][mid+1]);     // checking if 'right' side is a valid candidate for peak

            if(left_candidate==false && right_candidate==false) return {row,mid};         // If both are not valid then return considered element
            
            if(left_candidate) h=mid-1;
            else l=mid+1;
        }
        return {-1,-1};
    }
};