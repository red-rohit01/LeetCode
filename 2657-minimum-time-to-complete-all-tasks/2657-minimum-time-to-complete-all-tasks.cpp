class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),cmp);
        map<int,int>common_time;
        int ans=0;
        for(int i=0;i<tasks.size();++i)
        {
            for(int j=tasks[i][0];j<=tasks[i][1] && tasks[i][2]>0;++j) //If there is something left from earlier then We'll try to use them and it's been denoted by the common_time value of 'j' being '1'
            {
                if(common_time[j]==1) tasks[i][2]--;
            }

            for(int j=tasks[i][1];j>=tasks[i][0] && tasks[i][2]>0;--j)  // we'll try to mark from the later endpoints so that 'j' values can be used for later starting processes too.
            {
                if(common_time[j]==0)
                {
                    ans++;
                    tasks[i][2]--;
                    common_time[j]=1;
                }
            }
        }
        return ans;
    }
};