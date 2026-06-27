class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        map<int,int>rk;
        int ans=1;
        for(int i=0;i<n;++i) rk[nums[i]]++;

        map<int,int>res;
        int mx=0;
        if(rk.find(1)!=rk.end()) mx=max(mx,rk[1]);
        
        for(auto &x:rk)
        {
            int val=x.first;
            int curr=1;
            while(val>1)
            {
                //double p=pow(val,.5);
                int p=sqrtl(val);
                if((p*p)==val)
                {
                    if(rk.find(p)!=rk.end())
                    {
                        if(res.find(p)!=res.end() && rk[p]>=2)
                        {
                            curr+=res[p]+1;
                            break;
                        }
                        else if(rk[p]>=2)
                        {
                            curr+=2;
                            val=p;
                        }
                        else break;
                    }
                    else break;
                }
                else break;
            }
            res[x.first]=curr;
            ans=max(ans,curr);
        }
        if(mx>ans)
        {
            if(mx&1) return mx;
            return mx-1;
        }
        return ans;
    }
};