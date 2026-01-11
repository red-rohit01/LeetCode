class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans=0;
        stack<int>st;
        for(int i=0;i<=n;++i)
        {
            while(!st.empty() && (i==n || nums[i]<=nums[st.top()]))
            {
                int ind=st.top();
                st.pop();
                int left=-1;
                if(st.size()>0) left=st.top();
                ans-=(long long)(1LL*nums[ind]*1LL*(ind-left)*1LL*(i-ind));   // val*left_side_cnt*right_side_cnt
            }
            st.push(i);
        }
        st.pop();
        for(int i=0;i<=n;++i)
        {
            while(!st.empty() && (i==n || nums[i]>=nums[st.top()]))
            {
                int ind=st.top();
                st.pop();
                int left=-1;
                if(st.size()>0) left=st.top();
                ans+=(long long)(1LL*nums[ind]*1LL*(ind-left)*1LL*(i-ind));
            }
            st.push(i);
        }
        return ans;
    }
};