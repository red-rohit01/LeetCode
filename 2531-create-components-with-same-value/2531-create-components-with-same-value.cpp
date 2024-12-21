class Solution {
public:
    // The idea is to check for all of the divisors of (summartion of nums) and for each of the value check the number of valid
    // components possible. so, the answer will be (no_of_components-1)
    // helper funtion keeps track of the number of components having summation of values in each component equal 'k'.
    
    // In the below code I checked with prime values and (total/prime) values only and it's working fine but normally I should 
    // check with each value of divisors.

    // Maximum Total No. of Divisors for a N digit number
    // [1, 2,  3,   4,   5,   6,   7,   8,    9,   10,   11,   12,    13,    14,    15,    16,    17,     18,     19]
    // [4, 12, 32, 64, 128, 240, 448, 768, 1344, 2304, 4032, 6720, 10752, 17280, 26880, 41472, 64512, 103680, 161280]
    int helper(vector<int>adj[], vector<int>&nums,int st,int p,int &k,int &curr)
    {
        int val=nums[st];
        for(auto &x:adj[st])
        {
            if(x!=p)
            {
                int temp=helper(adj,nums,x,st,k,curr);

                val+=temp;
            }
        }
        if(val==k) 
        {
            curr++;
            return 0;
        }
        return val;
    }
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int total=0;
        int n=nums.size();
        for(auto &x:nums) total+=x;

        if(total==(n*nums[0])) return (n-1);//It actually signifies that all the nodes have equal value.So,simply remove (n-1) edges 
        
        vector<int>adj[n];

        for(int i=0;i<(n-1);++i)
        {
            int u=edges[i][0];
            int v=edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans=1;
        vector<int>divisors;
        int temp=total;
        for(int i=2;(i*i)<=temp;++i)
        {
            if((temp%i)==0)
            {
                while((temp%i)==0)
                {
                    temp/=i;
                    if(temp==0) break;
                }
                divisors.push_back(i);
                if((total/i)!=i) divisors.push_back(total/i);
            }
        }
        if(temp) divisors.push_back(temp);


        for(auto &k:divisors)
        {
            bool flag=true;
            for(int i=0;i<n;++i)
            {
                if(nums[i]>k) 
                {
                    flag=false;
                    break;
                }
            }
            if(flag==false) continue;

            int curr=0;
            int final=helper(adj,nums,0,-1,k,curr);
            if(final!=0) continue;   // If the component associated with root is not having summation equals 'k' Then not possible.
            ans=max(ans,curr);
        }
        return (ans-1);
    }
};