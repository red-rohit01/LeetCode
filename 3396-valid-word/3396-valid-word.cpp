class Solution {
public:
    bool isValid(string word) {
        int n=word.size();
        if(n<3) return false;
        
        int v=0,c=0;
        for(int i=0;i<n;++i)
        {
            if(word[i]=='A' || word[i]=='E' || word[i]=='I' || word[i]=='O' || word[i]=='U' || word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u') v++;
            
            else if(word[i]=='@' || word[i]=='#' || word[i]=='$') return false;
            
            else if(word[i]>='0' && word[i]<='9'){ }
            
            else c++;
        }
        
        return (v>0 && c>0);
    }
};