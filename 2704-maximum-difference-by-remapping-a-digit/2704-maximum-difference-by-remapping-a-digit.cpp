class Solution {
public:
    int minMaxDifference(int num) {
        string str=to_string(num);
        string mx=str;
        int l=0;
        while(mx[l]=='9') l++;
        char val=mx[l];
        int n=str.size();
        for(int i=0;i<n;++i)
        {
            if(mx[i]==val) mx[i]='9';
        }
        
        string mn=str;
        l=0;
        while(mn[l]=='0') l++;
        val=mn[l];
        for(int i=0;i<n;++i)
        {
            if(mn[i]==val) mn[i]='0';
        }
        
        int rk=stoi(mx);
        
        int dk=0;
        for(int i=0;i<n;++i)
        {
            int curr=mn[i]-'0';
            
            dk=(dk*10)+curr;
        }
        return (rk-dk);
    }
};