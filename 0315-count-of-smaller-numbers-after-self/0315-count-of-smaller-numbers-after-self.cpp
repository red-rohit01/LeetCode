class Solution {
public:
    // The idea is simple for each of the left part of merge sort division sort it's corrsponding right part and then check 
    // smaller elements with the help of lower_bound function on the right part of array.
    void merge(vector<int>&arr, int l,int mid, int r,vector<int>&count)
    {
        vector<int>second;
        for(int l=mid+1;l<=r;++l) second.push_back(arr[l]);
        
        sort(second.begin(),second.end());
        
        for(int p=l;p<=mid;++p)
        {
            int curr=arr[p];
            int ind=lower_bound(second.begin(),second.end(),curr)-second.begin();
            count[p]+=ind;
        }
    }
    void mergeSort(vector<int>& arr,int l,int r,vector<int>&count)
    {
        if(l>=r) return ;
        
        int mid=(l+r)/2;
        mergeSort(arr,l,mid,count);
        mergeSort(arr,mid+1,r,count);
        merge(arr,l,mid,r,count);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int size=nums.size();
        vector<int>count(size);                                            
        mergeSort(nums,0,size-1,count);                                
        return count;
    }
    
};