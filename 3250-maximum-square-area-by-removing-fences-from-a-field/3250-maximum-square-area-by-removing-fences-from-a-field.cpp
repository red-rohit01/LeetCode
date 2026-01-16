class Solution {
public:
    const long long mod=1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        long long ans=0;
        unordered_set<int>st;
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        for(int i=0;i<hFences.size();++i)
        {
            for(int j=i+1;j<hFences.size();++j)
            {
                st.insert(abs(hFences[i]-hFences[j]));
            }
        }

        for(int i=0;i<vFences.size();++i)
        {
            for(int j=i+1;j<vFences.size();++j)
            {
                long long curr=abs(vFences[j]-vFences[i]);
                if(st.find(curr)!=st.end())
                {
                    ans=max(ans,curr);
                }
            }
        }
        if(ans==0) return -1;
        return (ans*ans)%mod;
    }
};