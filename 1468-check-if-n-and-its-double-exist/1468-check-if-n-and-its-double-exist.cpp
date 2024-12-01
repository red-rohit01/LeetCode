class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int>st(arr.begin(),arr.end());

        int len=arr.size();
        int cnt_0=0;
        for(int i=0;i<len;++i)
        {
            if(arr[i]==0)
            {
                if(cnt_0>0) return true;

                cnt_0++;
                continue;
            }
            int req=2*arr[i];

            if(st.find(req)!=st.end()) return true;
        }
        return false;
    }
};