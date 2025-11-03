class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0;
        int n=colors.size();
        for(int i=0;i<n-1;++i)
        {
            if(colors[i]==colors[i+1])
            {
                vector<int>temp;
                temp.push_back(neededTime[i]);
                temp.push_back(neededTime[i+1]);
                int j=i+2;
                while(j<n && colors[j]==colors[i])
                {
                    temp.push_back(neededTime[j]);
                    j++;
                }
                i=j-1;
                sort(temp.begin(),temp.end());
                for(int l=0;l<temp.size()-1;++l)
                {
                    ans+=temp[l];
                }
            }
        }
        return ans;
    }
};