class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int len=strs[0].size();

        int del=0;
        vector<bool>isSorted(n-1);    //isSorted[i] is true ==> if and only if strs[i]<=strs[i+1] i.e., rows already sorted
        for(int j=0;j<len;++j)
        {
            int i=0;
            for(;i<n-1;++i)   // traverse each row to check if current column is valid or not
            {
                if(isSorted[i]==false && strs[i][j]>strs[i+1][j])         // If this particular row value is greater than the next one
                {
                    del++;
                    break;
                }
            }

            if(i<n-1) continue; // If current column is invalid, we should delete this and shouldn't proceed to make it sorted as it will be deleted  
            
            // column will not be deleted, we will investigate if this is because of
            // duplicate characters or string is really sorted in lexicographic order.
            // in case of dupes we want to keep sorted value as false                 TC: ["xya", "xpb", "zqc"]
            // and skip the dupe chars so we can investigate the string further for next column        
            for(int i=0;i<n-1;++i) 
            {
                isSorted[i]= isSorted[i] || (strs[i][j]<strs[i+1][j]);
            }
        }
        return del;
    }
};