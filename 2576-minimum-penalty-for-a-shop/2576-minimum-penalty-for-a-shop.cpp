class Solution {
public:
    int bestClosingTime(string customers) {
        int y=0,no=0;
        int n=customers.size();
        vector<int>pre(n),suf(n);   //pre[i]--> counts of 'N' till 'i-1'th index and suf[i]--> counts no. of 'Y' from 'i' onward
        if(customers[0]=='N') no++;
        for(int i=1;i<n;++i)
        {
            pre[i]=no;
            if(customers[i]=='N') no++;
        }

        for(int i=n-1;i>=0;--i)
        {
           if(customers[i]=='Y') y++;
           suf[i]=y;
        }
        
        int ans=0;
        int mn=n;
        for(int i=0;i<n;++i)
        {
            int sum=pre[i]+suf[i];
            if(sum<mn)
            {
                mn=sum;
                ans=i;
            }
        }
        if(no<mn) return n;       // To check the closing of shop at n'th hour as this hasn't been checked with for loop
        return ans;
    }
};