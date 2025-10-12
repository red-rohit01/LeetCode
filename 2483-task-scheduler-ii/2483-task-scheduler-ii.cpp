class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        int n=tasks.size();
        long long ans=0;
        map<int,long long>prev;
        long long day=1;
        for(int i=0;i<n;++i)
        {
            if(prev.find(tasks[i])==prev.end())
            {
                prev[tasks[i]]=day;
                day=day+1LL;
            }
            else 
            {
                long long last_val=prev[tasks[i]];
                day=max(day,last_val+1LL*space+1LL);
                prev[tasks[i]]=day;
                day=day+1LL;
            }
        }
        return (day-1);
    }
};