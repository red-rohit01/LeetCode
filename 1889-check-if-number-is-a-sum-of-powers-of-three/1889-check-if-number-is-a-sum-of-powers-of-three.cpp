class Solution {
public:
    // Since, n<=1e7. so, At max we would be using only 3^16. so, check out all the possibilities. It's giving TLE
    // bool helper(int curr,int mask,int n)
    // {
    //     if(curr>n) return false;
    //     if(curr==n) return true;

    //     for(int i=0;i<=16;++i)
    //     {
    //         if((mask&(1<<i))==0)
    //         {
    //             int val=pow(3,i);
    //             mask=(mask^(1<<i));
    //             if((curr+val)<=n)
    //             {
    //                 if(helper(curr+val,mask,n)) return true;
    //             }
    //             mask=(mask^(1<<i));
    //         }
    //     }
    //     return false;
    // }
    bool checkPowersOfThree(int n) {
        // int mask=0;
        // int curr=0;
        // return helper(curr, mask,n);

        while(n)
        {
            if((n%3)==2) return false;

            n/=3;
        }        
        return true;
    }
};