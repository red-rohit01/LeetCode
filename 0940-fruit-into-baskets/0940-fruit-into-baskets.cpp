class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        set<int>st;
        map<int,int>rk;
        int ans=1;

        int i=0;
        int j=0;
        int n=fruits.size();
        while(j<n)
        {
            st.insert(fruits[j]);
            rk[fruits[j]]++;

            if(st.size()>2)
            {
                int temp=fruits[i];
                while(i<j)
                {
                    if(--rk[fruits[i]]==0)
                    {
                        st.erase(fruits[i]);
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