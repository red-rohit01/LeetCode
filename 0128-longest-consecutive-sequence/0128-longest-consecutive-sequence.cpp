class Solution {
public:
    // First turn the input into a set of numbers. That takes O(n) and then we can ask in O(1) whether we have a certain number.
    // Then go through the numbers. If the number x is the start of a streak (i.e., x-1 is not in the set), then test y = x+1, x+2, 
    // x+3, ... and stop at the first number y not in the set. The length of the streak is then simply y-x and we update our global 
    // best with that. Since we check each streak only once, this is overall O(n).  
    // This above one 'set' based solution is giving us TLE.

    // Approach 2: 
    /*
    Whenever a new element n is inserted into the map, do two things:

    See if n - 1 and n + 1 exist in the map, and if so, it means there is an existing sequence next to n. Variables left and right will 
    be the length of those two sequences, while 0 means there is no sequence and n will be the boundary point later. Store (left + right + 1)
    as the associated value to key n into the map.
    Use left and right to locate the other end of the sequences to the left and right of n respectively, and replace the value with the new 
    length.
    Everything inside the for loop is O(1) so the total time is O(n).
    */
    int longestConsecutive(vector<int>& nums) {

        int ans=0;
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;++i)
        {
            int val=nums[i];
            if(mp.find(val)!=mp.end()) continue;

            int left=0,right=0;
            if(mp.find(val-1)!=mp.end()) left=mp[val-1];
            if(mp.find(val+1)!=mp.end()) right=mp[val+1];

            int curr=left+right+1;
            ans=max(ans,curr);

            if(left>0) mp[val-left]=curr;
            if(right>0) mp[val+right]=curr;

            mp[val]=curr;
        }
        return ans;
        // unordered_set<int>s(nums.begin(),nums.end());
        // int ans=0;
        // int n=nums.size();
        // for(int i=0;i<n;++i)
        // {
        //     if(s.find(nums[i]-1)==s.end())
        //     {
        //         int last=nums[i];
        //         while(s.find(last)!=s.end()) last++;
					
        //         ans=max(ans,last-nums[i]);
        //     }
        // }
        // return ans;
    }
};