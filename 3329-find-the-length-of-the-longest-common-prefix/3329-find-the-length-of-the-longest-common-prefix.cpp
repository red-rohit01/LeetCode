class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int m=arr2.size();

        set<int>st;
        for(int i=0;i<n;++i)
        {
            string num=to_string(arr1[i]);
            int val=0;
            for(int j=0;j<num.size();++j)
            {
                val=val*10 +(num[j]-'0');
                if(val>0) st.insert(val);
            }
        }
        
        int ans=0;
        for(int i=0;i<m;++i)
        {
            string num=to_string(arr2[i]);
            int val=0;
            for(int j=0;j<num.size();++j)
            {
                val=val*10 +(num[j]-'0');
                if(val>0)
                {
                    if(st.find(val)!=st.end())
                    {
                        ans=max(ans,j+1);
                    }
                    else break;
                }
            }
        }
        return ans;
    }
};