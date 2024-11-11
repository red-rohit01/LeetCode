class Solution {
public:
    vector<int>prime;
    void sieve(int mx)
    {
       prime.resize(mx+5,1);
       prime[0]=0;
        prime[1]=0;
        for(int i=2;i*i<=mx;++i)
        {
            for(int j=i*i;j<=mx;j+=i)
            {
                prime[j]=0;
            }
        }   
    }
    bool primeSubOperation(vector<int>& nums) {
//         int mx=1001;
//         vector<int>sieve(mx,1);
//         set<int>st;
//         sieve[0]=0;
//         sieve[1]=0;
//         for(int i=2;i*i<=mx;++i)
//         {
//             for(int j=i*i;j<=mx;j+=i)
//             {
//                 sieve[j]=0;
//             }
//         }
        
//         for(int i=1;i<=mx;++i) 
//         {
//             if(sieve[i]==1) st.insert(i);
//         } 
//         for(auto x:st) cout<<x<<" ";
        
        //int n=nums.size();
        //int val=nums[0];
//         if(val!=1)
//         {
//             auto x=st.lower_bound(val);
//             x--;
//             int temp=*x;
//             nums[0]=val%temp;
//         }
//         for(int i=1;i<n;++i)
//         {
//             int val=nums[i];
//             auto x=st.lower_bound(val);
//             x--;
//             int temp=*x;
//             nums[i]=val%temp;
//             if(nums[i]<=nums[i-1]) nums[i]+=temp;
//         }
        
//         for(int i=0;i<(n-1);++i)
//         {
//             if(nums[i]>=nums[i+1]) return false;
//         }
        
//         return true;
        sieve(1001);
        int last=0;
        int n=nums.size();
        for(int i=0;i<n;++i)
        {
            if(nums[i]<=last) return false;
            
            for(int val= last+1;val<nums[i];++val)
            {
               if(prime[nums[i]-val]==1)
               {
                   nums[i]=val;
                    break;
               }
           }
          last=nums[i];
        }
        return true;
    }
};