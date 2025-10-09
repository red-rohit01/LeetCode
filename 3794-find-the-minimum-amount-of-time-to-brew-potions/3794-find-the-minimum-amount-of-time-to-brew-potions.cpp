class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size();
        int m=mana.size();

        vector<long long>minFreeTime(n+1);
        for(int j=0;j<m;++j)
        {
            for(int i=0;i<n;++i)
            {
                minFreeTime[i+1]=max(minFreeTime[i+1],minFreeTime[i])+ 1LL*mana[j]*skill[i];
                //cout<<minFreeTime[i+1]<<" ";
            }
            //cout<<" - ";
            // Backward updates ensures the timing compatibility
            for(int i=n-1;i>0;--i) 
            {
                minFreeTime[i]=minFreeTime[i+1]-1LL*mana[j]*skill[i]; //cout<<minFreeTime[i+1]<<" ";
            }
            //cout<<minFreeTime[1];
            //cout<<"\n";
        }

        return minFreeTime[n];
    }
};