class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>rk;
        int ans=1;

        int i=0;
        int j=0;
        int n=fruits.size();
        while(j<n)
        {
            rk[fruits[j]]++;
            if(rk.size()>2)
            {
                int temp=fruits[i];
                while(i<j)
                {
                    if(--rk[fruits[i]]==0)
                    {
                        rk.erase(fruits[i]);
                        i++;
                        break;
                    } 
                    i++;
                }
            }
            ans=max(ans,(j-i+1));
            j++;
        }
        return ans;
    }
};