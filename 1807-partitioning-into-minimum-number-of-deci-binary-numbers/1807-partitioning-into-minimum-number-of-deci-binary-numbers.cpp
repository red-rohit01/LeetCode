class Solution {
public:
    int minPartitions(string n) {
        int len=n.size();
        int max_digit= 0;
        
        for(auto &element : n)
        {
            int digit=element-'0';
            max_digit=max(digit,max_digit);
        }
        return max_digit;
    }
};