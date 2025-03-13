class Solution {
public:
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