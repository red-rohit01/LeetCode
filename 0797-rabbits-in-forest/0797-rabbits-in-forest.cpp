class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n=answers.size();
        map<int,int>freq;
        int ans=0;
        for(auto &x:answers) 
        {
            if(x==0)
            {
                ans++;
                continue;
            }
            freq[x]++;
        }
        for(auto &x:freq)
        {
            int val=x.first;
            int cnt=x.second;

            int groups=(cnt+val)/(val+1);
            ans+=groups*(val+1);
        }

        return ans;
    }
};