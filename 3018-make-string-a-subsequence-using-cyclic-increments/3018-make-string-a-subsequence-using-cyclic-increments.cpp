class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        if(m>n) return false;
        
        int ind=0;
        for(int i=0;i<n && ind<m;++i)
        {
            if(str2[ind]==str1[i]) ind++;
            else if(((str1[i]-97)+1)%26 +'a' ==str2[ind]) ind++;
        }
        if(ind==m) return true;
        return false;
    }
};