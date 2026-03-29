class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        map<int,int>rk,dk;
        for(int i=0;i<4;++i)
        {
            rk[s1[i]-'a']++;
            dk[s2[i]-'a']++;
        }
        if(rk!=dk) return false;
        
        if(s1[0]!=s2[0])
        {
            if(s1[0]!=s2[2]) return false;
            
            swap(s2[2],s2[0]);
        }
        
        if(s1[1]!=s2[1])
        {
            if(s1[1]!=s2[3]) return false;
            
            swap(s2[1],s2[3]);
        }
            
        if(s1[2]!=s2[2]) return false;
        
        if(s1[3]!=s2[3]) return false;
        
        return true;
    }
};