class Solution {
public:
    // One of the good variation would be to build the second largest number by rearranging the digits
    // e.g., [5,9,7,6,6,3,9,6,3,3,6]
    // largest_no [9,9,7,6,6,6,6,5,3,3,3]
    // second largest_no --> swap first position from right where they differ   --> [9,9,7,6,6,6,6,3,5,3,3] 
    int maximumSwap(int num) {
        string str=to_string(num);
        vector<int>right_index(10,-1);

        int len=str.size();
        for(int i=0;i<len;++i)
        {
            int val=str[i]-'0';
            right_index[val]=i;
        }

        for(int i=0;i<len;++i)
        {
            int val=str[i]-'0';
            for(int j=9;j>val;--j)
            {
                if(right_index[j]>i) 
                {
                    swap(str[i],str[right_index[j]]);
                    return stoi(str);
                }
            }
        }
        return stoi(str);
    }
};