class Solution {
public:
    int bestClosingTime(string customers) {
        int y=0;
        int n=customers.size();
        vector<int>suf(n);   // suf[i]--> counts no. of 'Y' from 'i' onward
        for(int i=n-1;i>=0;--i)
        {
           if(customers[i]=='Y') y++;
           suf[i]=y;
        }
        
        int ans=0;
        int mn=n;
        int pre=0;
        for(int i=0;i<n;++i)
        {
            int sum=pre+suf[i];
            if(sum<mn)
            {
                mn=sum;
                ans=i;
            }
            if(customers[i]=='N') pre++;
        }
        if(pre<mn) return n;       // To check the closing of shop at n'th hour as this hasn't been checked with for loop
        return ans;
    }
};