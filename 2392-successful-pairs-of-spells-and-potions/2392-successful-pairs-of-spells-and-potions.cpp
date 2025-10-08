class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;
       
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++)
        {
            int m=potions.size();
            int l=0,h=m-1;
            int cnt=m;
            while(l<=h)
            {
                int mid=(l+h)/2;
                if(1LL*spells[i]*potions[mid]>=success)
                {
                    cnt=mid;
                    h=mid-1;
                }
                else
                {
                    l=mid+1;
                }
                
            }
            ans.push_back(m-cnt);
        }
        return ans;
    }
};