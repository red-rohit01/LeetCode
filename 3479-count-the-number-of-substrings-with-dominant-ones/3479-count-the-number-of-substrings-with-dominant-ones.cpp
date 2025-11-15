class Solution {
public:
    int numberOfSubstrings(string s) {
        int len=s.size();
        vector<int>zeroInd;
        for(int i=0;i<len;++i)
        {
            if(s[i]=='0') zeroInd.push_back(i);
        }

        int ones=len-zeroInd.size();
        zeroInd.push_back(len);

        int ans=0;
        int sid=0;
        
        for(int left=0;left<len;++left)
        {
            for(int id=sid;id<zeroInd.size()-1;++id)
            {
                int cnt0=id-sid+1;
                if((cnt0*cnt0)>ones) break;

                int prev=zeroInd[id];
                int nxt=zeroInd[id+1];

                int cnt1=zeroInd[id]-left-(id-sid);

                if(cnt1>=(cnt0*cnt0)) ans+=(nxt-prev);

                else ans+=max(nxt-prev-(cnt0*cnt0-cnt1),0);
            }
            if(s[left]=='0') sid++;
            else
            {
                ans+=zeroInd[sid]-left;
                ones--;
            }
        }
        return ans;
    }
};