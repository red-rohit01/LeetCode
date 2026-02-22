class Solution {
public:
    int binaryGap(int n) {
        int ans=0;
        int prev=-1;
        int ind=0;
        while(n)
        {
            int bit=n&1;
            if(bit==1)
            {
                if(prev==-1) prev=ind;
                else 
                {
                    ans=max(ans,(ind-prev));
                    prev=ind;
                }
            }
            n>>=1;
            ind++;
        }
        return ans;
    }
};