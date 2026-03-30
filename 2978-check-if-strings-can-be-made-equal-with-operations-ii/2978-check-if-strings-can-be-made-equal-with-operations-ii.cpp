class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.size();
        
        vector<int>temp1,temp2;
        for(int i=0;i<n;i+=2)
        {
            temp1.push_back(s1[i]-'a');
            temp2.push_back(s2[i]-'a');
        }
        sort(temp1.begin(),temp1.end());
        sort(temp2.begin(),temp2.end());
        if(temp1!=temp2) return false;
        
        temp1.clear();
        temp2.clear();
        
        for(int i=1;i<n;i+=2)
        {
            temp1.push_back(s1[i]-'a');
            temp2.push_back(s2[i]-'a');
        }
        sort(temp1.begin(),temp1.end());
        sort(temp2.begin(),temp2.end());
        if(temp1!=temp2) return false;
        
        return true;
        
    }
};