class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n=costs.size();
        vector<pair<int,int>>comb;
        int singleMachine=0;
        for(int i=0;i<n;++i)
        {
            comb.push_back({costs[i],capacity[i]});
            if(costs[i]<budget) singleMachine=max(singleMachine, capacity[i]);
        }

        sort(comb.begin(),comb.end());

        vector<int>prefMax(n);   // Stores Maximum capacity amound machines with index<=i
        prefMax[0]=comb[0].second;

        for(int i=1;i<n;++i) prefMax[i]=max(comb[i].second, prefMax[i-1]);
        
        int ans=singleMachine;
        for(int i=1;i<n;++i)
        {
            if(comb[i].first>=budget) return ans;

            int secondMachine=-1;
            int l=0,h=i-1;
            while(l<=h)
            {
                int mid=l+(h-l)/2;
                if(comb[mid].first<(budget-comb[i].first))
                {
                    secondMachine=prefMax[mid];
                    l=mid+1;
                }
                else h=mid-1;
            }

            if(secondMachine!=-1) ans=max(ans, secondMachine+comb[i].second);    //Update the answer with capacity[i] + prefMax[j]
        }
        return ans;
    }
};