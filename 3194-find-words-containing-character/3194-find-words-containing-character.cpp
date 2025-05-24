class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>rohit;
        int n=words.size();
        for(int i=0;i<n;++i)
        {
            string temp=words[i];
            for(int j=0;j<temp.size();++j)
            {
                if(temp[j]==x)
                {
                    rohit.push_back(i);
                    break;
                }
            }
        }
        return rohit;
    }
};