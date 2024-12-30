class Solution {
public:
    // Normal Take/ Not Take approach will give us TLE as the maximum reward possible is 'maxm' sum available in the vector. 
    // and Thus the Time Complexity would ne O(n* maxm) == O(25*1e8)

    int maxTotalReward(vector<int>& rewardValues) {
        // vector<unordered_map<int,int>>dp(n,unordered_map<int,int>());

        // sort(rewardValues.begin(), rewardValues.end());
        // int n=rewardValues.size();
        // bool dp[50000]={};
        // dp[0]=true;
        // int maximum_reward=0;
        // for (int i=0;i<n;++i) 
        // {
        //     if (i==0 || rewardValues[i-1]!=rewardValues[i]) 
        //     {
        //         int limit=min(rewardValues[i], rewardValues[n-1]-rewardValues[i]);
        //         for (int j=0;j<limit;++j) 
        //         {
        //             if (dp[j]) 
        //             {
        //                 dp[j+rewardValues[i]] = true;
        //                 maximum_reward = max(maximum_reward, j + rewardValues[i]);
        //             }
        //         }
        //     }
        // }
        // return (maximum_reward+rewardValues[n-1]);

        //Is line Ka Simple yehi mtlb ha
    // dp |= (dp << shift >> shift << val);
    // phlay left Shift krke jo bhi uss number se brde number ha unko hata dai kyuki Sawal ke anushar hum uss number se brda number yeh uske barabar ka number nhi leskte
    // or wapis se right shift krke uske position purane fesbible bits ko wapis unki jagah pr le aye or fir val se left shift krke added contrubition ke bit ko set krdia and usko current ke sath
    // OR krke sare contribution ko le liya

    // App iski Jagah pe bitset<> Mask use krskte bas Mask ko current ke sath curr |= (Mask& new) << val

    // TC: O(n*(mxm/64))  why '64'? because compiler performs the bit operations in chunk of '32' or '64'. This minor optimization will work here.
        bitset<100001> dp; dp[0] = true;
        sort(rewardValues.begin(), rewardValues.end());
        for(auto val: rewardValues) 
        {
            int shift = 1e5 - (val - 1);
            dp|=(dp<< shift >> shift << val);   // can be written as this too.  dp |= (((dp << shift )>> shift) << val);
        }
        int res=1e5;
        while(!dp[res]) --res;
        return res;
    }
};