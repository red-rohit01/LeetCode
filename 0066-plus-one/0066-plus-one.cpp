class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len=digits.size();
        int carry=1;
        for(int i=len-1;i>=0;--i)
        {
            int curr=digits[i]+carry;
            digits[i]=curr%10;
            carry=curr/10;
        }

        if(carry==0) return digits;

        vector<int>ans={1};
        for(int i=0;i<len;++i) ans.push_back(digits[i]);
        return ans;
    }
};