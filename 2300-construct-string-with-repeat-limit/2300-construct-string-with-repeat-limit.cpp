class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n=s.size();
        vector<int>freq(26);
        for(auto &x:s)
        {
            freq[x-'a']++;
        }

        string ans="";
        bool flag=true;
        while(flag)
        {
            flag=false;
            int first=-1;
            int second=-1;

            for(int i=25;i>=0;--i)
            {
                if(freq[i]>0)
                {
                    if(first==-1)
                    {
                        first=i;
                    }
                    else if(second==-1) second=i;

                    else break;
                }
            }

            if(first==-1) return ans;   // No element left to add

            if(ans.size()==0) // 'ans' already empty then simply add the largest value character.
            {
                int mn=min(freq[first],repeatLimit);
                for(int j=0;j<mn;++j) ans+=(char)('a'+first);
                freq[first]-=mn;
                flag=true;
            }
            else
            {
                int prev=(ans.back()-'a');

                if(prev==first)
                {
                    if(second==-1) return ans;  // It denotes there is only one suitable element which is first but we can't 
                    else                        // put it because of the repeatLimit
                    {
                        flag=true;
                        ans+=(char)('a'+second);   // Since our goal is to have lexicographically largest so just adding '1' 
                        freq[second]--;  // element to break the continuous repeatLimit and in next iteration, I'll put first
                    }                   // as it'll add to larger lexicograph
                }
                else 
                {
                    int mn=min(freq[first],repeatLimit);
                    for(int j=0;j<mn;++j) ans+=(char)('a'+first);
                    freq[first]-=mn;
                    flag=true;
                }
            }
        }
        return ans;
    }
};