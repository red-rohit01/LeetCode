class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        int cnt=0;
        if(n%2==1) 
        {
            ans.push_back(0);
            cnt++;
        }
        int val=1;
        while(cnt<n)
        {
            ans.push_back(val);
            ans.push_back(-1*val);
            cnt+=2;
            val++;
        }
        return ans;
    }
};