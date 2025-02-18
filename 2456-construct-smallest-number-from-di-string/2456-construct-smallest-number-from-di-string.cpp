class Solution {
public:
    // Idea is inspired from here:
    // 1 2 3 4 5 6 7 8 9
    // D D I D D I D D

    // Match the input string and the sequence 1,2,3,4,5,6,7,8,9.
    // Reverse all numbers between "I".

    // For example:
    // first 'I' at 3, then reverse1,2,3, we have3,2,1
    // second 'I' at 6, then reverse4,5,6, we have6,5,4
    // Reverse the last group7,8,9, we have9,8,7

    // Final result for D D I D D I D D,
    // is 3,2,1,6,5,4,9,8,7

    string smallestNumber(string pattern) {
        int len=pattern.size();
        string ans;
        for(int i=1;i<=(len+1);++i) ans+=i+'0';
      
        for(int i=0;i<len;++i)
        {
            int k=i;
            while(k>=0 && pattern[k]=='D')
            {
                swap(ans[k+1],ans[k]);
                k--;
            }

        }
        return ans;
    }
};