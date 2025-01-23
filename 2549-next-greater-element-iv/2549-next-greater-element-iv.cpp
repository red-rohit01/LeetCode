class Solution {
public:
    // We would be using stack to find the first greater element but before popping it we add it to a min 'pq'. So, the elements inside
    // min 'pq' is assured to have already encountered there first Greater Element for sure.

    // Here min 'pq' is of type pair where first element is the actual value and the second element is the index number of that value.
    // Now, coming the check for min 'pq'. My idea is that if my current element can be a potential 'ans' value for the elements inside 
    // min 'pq' or not. And how would I check...? 
    // simply while the current index element is greater than 'pq' top element. I can always assign this current value Because for all
    // the elements inside 'pq' there first element has been encountered earlier and this current index value is greater than itself. so,
    // It must be the second larger value.

    vector<int> secondGreaterElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        stack<int>st;   // To keep track of the first greater element
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        for(int i=0;i<n;++i) 
        {
            while(!pq.empty() && pq.top().first<nums[i]) 
            {
                ans[pq.top().second] = nums[i];
                pq.pop();
            }

            while(!st.empty() && nums[st.top()]<nums[i]) 
            {
                pq.push({nums[st.top()], st.top()});
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};