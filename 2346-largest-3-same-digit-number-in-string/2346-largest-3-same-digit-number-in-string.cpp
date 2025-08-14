class Solution {
public:
    string largestGoodInteger(string num) {
        char res=0;
        int n=num.size();
        for(int i=2;i<n;++i)
        {
            if (num[i]==num[i-1] && num[i]==num[i-2]) res=max(res,num[i]);
        }
        return res==0?"":string(3, res);
    }
};