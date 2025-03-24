class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n=meetings.size();
        sort(meetings.begin(),meetings.end());
        int ans=0;
        int prev=1;
        for(int i=0;i<n;++i)
        {
            int temp=meetings[i][0]-prev;
            if(temp>0) ans+=temp;
            prev=max(prev,meetings[i][1]+1);
        }
        if(prev<=days) ans+=(days-prev+1);
        return ans;
    }
};