class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int val=num1;val<=num2;++val)
        {
            string str=to_string(val);
            int l=str.size();
            for(int i=1;i<l-1;++i)
            {
                if(str[i-1]<str[i] && str[i]>str[i+1]) ans++;

                if(str[i-1]>str[i] && str[i]<str[i+1]) ans++;
            }
        }
        return ans;
    }
};