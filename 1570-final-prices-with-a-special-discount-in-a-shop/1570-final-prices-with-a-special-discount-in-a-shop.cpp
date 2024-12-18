class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        stack<int>st;
        vector<int>right_smaller(n,n);  // Keeping track of the index having nearest smaller/equal value to its right
        for(int i=n-1;i>=0;--i)
        {
            while(!st.empty() && (prices[st.top()]>prices[i])) st.pop();

            if(!st.empty()) right_smaller[i]=st.top();

            st.push(i);
        }

        vector<int>ans(n);
        for(int i=0;i<n;++i)
        {
            int discount=0;
            if(right_smaller[i]!=n) discount=prices[right_smaller[i]];

            ans[i]=(prices[i]-discount);
        }
        return ans;
    }
};