class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int len=fruits.size();
        vector<int>placed(len,-1);
        int ans=len;
        for(int i=0;i<len;++i)
        {
            for(int j=0;j<len;++j)
            {
                if(baskets[j]>=fruits[i] && placed[j]==-1)
                {
                    placed[j]=1;
                    ans--;
                    break;
                }
            }
        }
        return ans;
    }
};