class Solution {
public:
    // The idea is that for each of the element calculate the nearest smaller to it's right and nearest smaller to it's left. so, for
    // this particular range our element under consideration would surely be the smallest number. 
    const int mod=1000000007;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        stack<int>st,st2;

        vector<int>nsr(n),nsl(n);  
        for(int i=0;i<n;++i)
        {
            nsl[i]=i;
            nsr[i]=(n-i-1);
        }

        // Any one of the side should handle the equal to scenario too.
        for(int i=n-1;i>=0;--i)
        {
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();

            if(!st.empty()) nsr[i]=st.top()-i-1;

            st.push(i);
        }

        for(int i=0;i<n;++i)
        {
            while(!st2.empty() && arr[st2.top()]>arr[i]) st2.pop();

            if(!st2.empty()) nsl[i]=i-st2.top()-1;

            st2.push(i);
        }
        
        long long ans=0;
        for(int i=0;i<n;++i)
        {
            long long temp=1LL*arr[i]*(nsl[i]+1)*(nsr[i]+1);

            ans=(ans %mod + temp %mod) %mod;
        }
        return ans;   
    }
};