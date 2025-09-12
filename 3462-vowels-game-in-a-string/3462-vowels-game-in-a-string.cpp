class Solution {
public:
    bool doesAliceWin(string s) {
        for(auto &x:s)
        {
            if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u') return true;
        }
        return false;
    }
};