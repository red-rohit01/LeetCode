class Solution {
public:
    vector<int>leftMinHelper(vector<int>&arr)
    {
        int n=arr.size();
        vector<int>ans(n,-1);
        
        stack<int>st;
        
        for(int i=0;i<n;++i)
        {
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            
            if(!st.empty()) ans[i]=st.top();
            
            st.push(i);
        }
        
        return ans;
    }

    vector<int>leftMaxHelper(vector<int>&arr)
    {
        int n=arr.size();
        vector<int>ans(n,-1);
        
        stack<int>st;
        
        for(int i=0;i<n;++i)
        {
            while(!st.empty() && arr[st.top()]<=arr[i]) st.pop();
            
            if(!st.empty()) ans[i]=st.top();
            
            st.push(i);
        }
        
        return ans;
    }

    vector<int>rightMinHelper(vector<int>&arr)
    {
        int n=arr.size();
        vector<int>ans(n,n);
        
        stack<int>st;
        
        for(int i=n-1;i>=0;--i)
        {
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
            
            if(!st.empty()) ans[i]=st.top();
            
            st.push(i);
        }
        
        return ans;
    }

    vector<int>rightMaxHelper(vector<int>&arr)
    {
        int n=arr.size();
        vector<int>ans(n,n);
        
        stack<int>st;
        
        for(int i=n-1;i>=0;--i)
        {
            while(!st.empty() && arr[st.top()]<arr[i]) st.pop();
            
            if(!st.empty()) ans[i]=st.top();
            
            st.push(i);
        }
        
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int>leftMin=leftMinHelper(nums);
        vector<int>leftMax=leftMaxHelper(nums);
        
        vector<int>rightMin=rightMinHelper(nums);
        vector<int>rightMax=rightMaxHelper(nums);
        
        
        long long unfairValue=0;
        for(int i=0;i<n;++i)
        {
            long long mnCnt=1LL*(i-leftMin[i])*1LL*(rightMin[i]-i);
            long long mxCnt=1LL*(i-leftMax[i])*1LL*(rightMax[i]-i);
            
            unfairValue+=mxCnt*1LL*nums[i];
            unfairValue-=mnCnt*1LL*nums[i];
        }
        return unfairValue;
    }
};