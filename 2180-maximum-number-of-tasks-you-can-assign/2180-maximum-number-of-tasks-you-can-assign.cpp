class Solution {
public:
    // The idea is to check 'mid' number of lower tasks with the mid no. of higher strength workers.
    bool check(int mid,vector<int>& tasks,int n,vector<int>& workers,int m,int pills,int strength)
    {
        int cnt=0;
        multiset<int>st(workers.begin()+(m-mid),workers.end());// Taking into account the 'mid' number of higher work strength workers.
        for(int i=mid-1;i>=0;--i)
        {
            auto it=st.lower_bound(tasks[i]);
            if(it==st.end())
            {
                pills--;
                it=st.lower_bound(tasks[i]-strength);
            }
            if((it==st.end() || pills<0)) return false;

            st.erase(it);
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n=tasks.size();
        int m=workers.size();
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());
        int l=0;
        int h=min(n,m);
        int ans=0;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(check(mid,tasks,n,workers,m,pills,strength))
            {
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        return ans;
    }
};