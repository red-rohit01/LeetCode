class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='1')
            {
                cnt++;
                int j=i+1;
                while(j<n && s[j]=='1') j++;

                i=j-1;
            }
        }
        return (cnt<=1);
    }
};