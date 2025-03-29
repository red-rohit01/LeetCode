class Solution {
public:
    const int mod=1e9+7;
    long long modexpo(long long a,long long b)
    {
        if(b==0) return 1;

        long long p=modexpo(a,b/2);
        p=(p%mod * p%mod)%mod;

        if(b%2==1) return (a%mod *p%mod)%mod;

        return p;
    }
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>primeScores(n);

        for(int ind=0;ind<n;++ind)
        {
            int val=nums[ind];
            int cnt=0;
            for(int j=2;(j*j)<=val;++j)
            {
                if(val%j==0)
                {
                    cnt++;
                    while(val%j==0)
                    {
                        val/=j;
                    }
                }
                if(val==1) break;
            }
            if(val>1) cnt++;
            primeScores[ind]=cnt;   
        }
        
        
        vector<int>ngl(n,-1);
        vector<int>ngr(n,n);
        stack<int>st;
        for(int i=0;i<n;++i)
        {
            int val=primeScores[i];
            while(st.size()>0 && primeScores[st.top()]<val)
            {
                int top_ind=st.top();
                st.pop();
                ngr[top_ind]=i;
            }

            if(!st.empty()) ngl[i]=st.top();

            st.push(i);
        }
        
        vector<long long>freq(n);
        for(int i=0;i<n;++i)
        {
            long long val1=i-ngl[i];
            long long val2=ngr[i]-i;
            
            long long cnt=val1*val2;
            freq[i]=cnt;
        }
        
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;++i) pq.push({nums[i],i});

        long long ans=1;
        
        while(!pq.empty() && k>0)
        {
            auto temp=pq.top();
            pq.pop();
            long long val=temp.first;
            long long cnt=freq[temp.second];

            long long opr=min((long long)k,cnt);
            ans=(ans%mod *modexpo(val,opr)%mod)%mod;

            k-=opr;
        }
        return ans;
    }
};