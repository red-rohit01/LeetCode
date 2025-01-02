class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        vector<int> idx;
        idx.push_back(0);
        for (int i=1;i<n;++i)
        {
            if (s[i]=='0')
            {
                for (int j=idx.size()-1;j>=0;j--) //Start searching from the last reachable 0 to decrease time complexity
                {
                    if (idx[j]+minJump<=i&&idx[j]+maxJump>=i)
                    {
                        idx.push_back(i);
                        break;
                    }
                }
            }
        }
        return idx.back()==n-1; 
    }
};