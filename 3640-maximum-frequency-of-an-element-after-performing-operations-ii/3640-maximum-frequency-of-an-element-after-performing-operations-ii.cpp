class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int len=nums.size();
        sort(nums.begin(),nums.end());
        int ans=1;
        int curr=0;
        vector<vector<int>>period;
        map<int,int>freq;
        set<int>st;
        for(int i=0;i<len;++i)
        {
            freq[nums[i]]++;
            int l_val=nums[i]-k;
            int h_val=nums[i]+k+1;
            
            period.push_back({l_val,1});
            period.push_back({h_val,-1});
            
            st.insert(nums[i]);
            st.insert(l_val);
            st.insert(h_val);
        }
        
        sort(period.begin(),period.end());
        
        int i=0;
        int n=period.size();
        for(auto &x:st)
        {
            while(i<n && period[i][0]<=x) 
            {
                curr+=period[i][1];
                ++i;
            }
            
            int curr_cnt=0;
            if(freq.find(x)!=freq.end()) curr_cnt=freq[x];
            
            int val=curr_cnt+min(numOperations,curr-curr_cnt);    // For a particular range number of elements equal '9' and we want to make
            // all of them equal to '6' and the freq of '6' is 2 then number of operations required to convert this range elements to '6' is 
            // 9-2(as 2 of them are already 6) and total current max frequency= 2+min{5,(9-2)} as max allowed numOperations is 5
            ans=max(ans,val);
        }
        return ans;

        // long long n=nums.size();
        // sort(nums.begin(),nums.end());
        // long long ans=1;
        // unordered_map<long long,long long>freq;
        // for(auto &x:nums) freq[x]++;

        // long long left=0;
        // long long right=0;

        // // First check: checking an existing number as the candidate 
        // for(long long mid=0;mid<n;++mid)
        // {
        //     while(nums[mid]-nums[left]>k) left++;

        //     while(right<n && (nums[right]-nums[mid])<=k) right++;

        //     long long total=right-left;
        //     long long curr=freq[nums[mid]]+min(1LL*numOperations,total-freq[nums[mid]]);
        //     ans=max(ans,curr);
        // }

        // // Second Check: It's bit tricky here. It's checking any of the midway element to be the candidate as in case of this TC:
        // // [13,13,20,20], numOperations=4, k=4. Here suitable candidate is '17'. 
        // // Here in this scenario: For any choosen element, num[right] would act as the right endpolong long of the window. so, left element 
        // // would be 2*k distance away.

        // left=0;
        // for(right=0;right<n;++right)
        // {
        //     while(1LL*nums[left]+2LL*k<1LL*nums[right]) left++;

        //     ans=max(ans,min(1LL*numOperations, right-left+1));
        // }
        // return ans;
    }
};