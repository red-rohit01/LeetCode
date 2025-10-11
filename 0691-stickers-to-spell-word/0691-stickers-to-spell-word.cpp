class Solution {
public:
    // dp[i][j]-->represents that minimum stickers out of first 'i' stickers to build till 'j' mask
    // The idea is to try out all the possibilities to create the characters of target....which we can check via mask
    int helper(int ind,int curr_mask,vector<string>&stickers,string &target,vector<vector<int>>&dp,int &mask)
    {
        if(curr_mask==mask) return 0;
        int n=stickers.size();
        if(ind>=n) return 1e9;

        if(dp[ind][curr_mask]!=-1) return dp[ind][curr_mask];

        int not_take=helper(ind+1,curr_mask,stickers,target,dp,mask);
        int take=1e9;
        int prev=curr_mask;
        int len=target.size();
        bool flag=false;
        for(int i=0;i<stickers[ind].size();++i)
        {
            for(int l=0;l<len;++l)
            {
                if(stickers[ind][i]==target[l])
                {
                    if((curr_mask&(1<<l))!=0) continue;   // If already found then no need to make another call

                    else 
                    {
                        curr_mask=(curr_mask|(1<<l));
                        flag=true;
                        break;
                    }
                }
            }
        }

        if(flag)
        {
            take=1+helper(ind,curr_mask,stickers,target,dp,mask);
        }

        return dp[ind][prev]=min(take,not_take);
    }
    int minStickers(vector<string>& stickers, string target) {
        int n=stickers.size();
        int len=target.size();
        int mask=(1<<len)-1;
        vector<vector<int>>dp(n+1,vector<int>(mask+1,-1));  
        int ans=helper(0,0,stickers,target,dp,mask);
        if(ans==1e9) return -1;
        return ans;
    }
};