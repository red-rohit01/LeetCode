class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n=queries.size();
        int m=dictionary.size();
        int p=queries[0].size();
        vector<string>ans;
        for(int i=0;i<n;++i)
        {
            string str=queries[i];
            for(int j=0;j<m;++j)
            {
                int cnt=0;
                string temp=dictionary[j];
                for(int k=0;k<p;++k)
                {
                    if(str[k]!=temp[k]) cnt++;
                    if(cnt>2) break;
                }
                if(cnt<=2)
                {
                  ans.push_back(str);
                  break;
                }
            }
        }
        return ans;
    }
};