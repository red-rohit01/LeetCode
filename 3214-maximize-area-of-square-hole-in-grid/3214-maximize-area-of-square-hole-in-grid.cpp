class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int cnt_mx1=1,cnt_mx2=1;
        int a=hBars.size();
        int b=vBars.size();
        for(int i=0;i<a;++i)
        {
            int j=i+1;
            while(j<a && hBars[j]==(hBars[j-1]+1)) j++;
            
            int cnt=j-i;
            cnt_mx1=max(cnt_mx1,cnt);
            i=j-1;
        }
        
        for(int i=0;i<b;++i)
        {
            int j=i+1;
            while(j<b && vBars[j]==(vBars[j-1]+1)) j++;
            
            int cnt=j-i;
            cnt_mx2=max(cnt_mx2,cnt);
            i=j-1;
        }
        
        int len=min(cnt_mx1,cnt_mx2);
        len++;
        int ans=len*len;
        return ans;
    }
};