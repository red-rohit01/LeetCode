class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int>str1;
        vector<int>str2;

        int n=version1.size(),m=version2.size();
        int c1=0,c2=0;
        int val=0;
        for(int i=0;i<=n;++i)
        {
            if(i==n || version1[i]=='.')
            {
                str1.push_back(val);
                val=0;
                if(version1[i]=='.') c1++;
            }
            else
            {
                int d=version1[i]-'0';
                val=(val*10)+d;
            }
        }

        for(int i=0;i<=m;++i)
        {
            if(i==m || version2[i]=='.')
            {
                str2.push_back(val);
                val=0;
                if(version2[i]=='.') c2++;
            }
            else
            {
                int d=version2[i]-'0';
                val=(val*10)+d;
            }
        }
        n=str1.size(),m=str2.size();
        while(c1<c2)  
        {
            str1.push_back(0);
            c1++;
        }

        while(c2<c1)
        {
            str2.push_back(0);
            c2++;
        } 
        for(int i=0;i<=c1;++i)
        {
            if(str1[i]<str2[i]) return -1;
            
            if(str1[i]>str2[i]) return 1;
        }
        return 0;
    }
};