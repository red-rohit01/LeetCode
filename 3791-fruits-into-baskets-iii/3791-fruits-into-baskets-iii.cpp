class Solution {
public:
    // Nice solution implementing the concept of Square Root Decomposition
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        vector<int>sector_mx;
        int sz=sqrt(n);     // size of each of the sector considering the square root decomposition

        int cnt=0, mx=0;
        for(int i=0;i<n;++i)
        {
            if(cnt==sz)
            {
                sector_mx.push_back(mx);
                // Now, updates for the next sector
                mx=baskets[i];
                cnt=1;
            }
            else 
            {
                cnt++;
                mx=max(mx,baskets[i]);
            }
        }

        sector_mx.push_back(mx);     // last sector

        int ans=n;
        for(int i=0;i<n;++i)
        {
            int ind=0;
            bool flag=false;

            for(int j=0;j<n;j+=sz)
            {
                if(sector_mx[ind]<fruits[i])
                {
                    ind++; // skip this segment
                    continue;
                }

                // First place to allocate the fruit
                for(int r=j;r<min(j+sz,n);++r)
                {
                    if(baskets[r]>=fruits[i])
                    {
                        ans--;
                        flag=true;
                        baskets[r]=-1;
                        break;
                    }
                }

                // Now update the maximum of this sector if fruit was allocated
                if(flag==true)
                {
                    int mx=baskets[j];
                    for(int r=j;r<min(j+sz,n);++r)
                    {
                        mx=max(mx,baskets[r]);
                    }
                    sector_mx[ind]=mx;
                    break;
                }
            }
        }
        return ans;
    }
};