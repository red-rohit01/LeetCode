class Solution {
public:
    // Since the values are allowed for '0' to 'n'. so, any element at index 'i' can give atmost 'i' number of inversions.
    // _,5,_,_,_,_,_,_,   [So, this '5' can give inversions equal '5' with values from '0' till '4']

    vector<int>req;
    int getAllCountOfPermutation(vector<vector<int>>&dp,int currentIndex,int InversionReq)
    {     
        if(currentIndex<=0)
        {
            if(InversionReq==0)
            {
               if(req[currentIndex]==-1 || req[currentIndex]==0) return 1;

               else return 0;
            }
            else return 0;
        }
        
        if(req[currentIndex]!=-1)
        {
            if(req[currentIndex]!=InversionReq) return 0;
        }
        
        if(dp[currentIndex][InversionReq]!=-1) return dp[currentIndex][InversionReq];
        
        int ans=0;

        for(int i=0;i<=min(currentIndex,InversionReq);i++)
        {
            ans+=getAllCountOfPermutation(dp,currentIndex-1,InversionReq-i);
            ans%=1000000007;
        }
        
        return dp[currentIndex][InversionReq]=ans;
    }
    
    int numberOfPermutations(int n, vector<vector<int>>& requirement) 
    {    
        req.resize(n,-1);
        sort(requirement.begin(),requirement.end());
        
        for(int i=0;i<requirement.size();++i)
        {
            req[requirement[i][0]]=requirement[i][1];
        }
        
        vector<vector<int>>dp(n,vector<int>(401,-1));
        
        int ans=getAllCountOfPermutation(dp,n-1,req[n-1]);
        return ans;
    }
};