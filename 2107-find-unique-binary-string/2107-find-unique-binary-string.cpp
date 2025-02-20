class Solution {
public:
    // bool helper(string &ans,set<string>&st,int n)
    // {
    //     if(ans.size()==n)
    //     {
    //         if(st.find(ans)==st.end()) return true;

    //         return false;
    //     }

    //     ans+='0';
    //     if(helper(ans,st,n)) return true;
    //     ans.pop_back();
    //     ans+='1';
    //     if(helper(ans,st,n)) return true;
    //     ans.pop_back();
    //     return false;
    // }
    string findDifferentBinaryString(vector<string>& nums) {
        // int n=nums[0].size();
        // set<string>st(nums.begin(),nums.end());

        // string ans="";
        // helper(ans,st,n); 
        // return ans;

        //The above solution is also working with O(2^n) but this solution has O(n).
        // Here, we are intentionally differing a particular element in each string so that 
        // the string obtained must be different from all of the string present in the vector.
        string ans=""; 
        int n=nums.size();
        for(int i=0;i<n;++i) 
        {
            char curr=nums[i][i];
            ans+=((curr=='0')?'1':'0');    // It'll surely ensure there is atleast one position where the 'char' differ.
        }
        return ans;
    }
};