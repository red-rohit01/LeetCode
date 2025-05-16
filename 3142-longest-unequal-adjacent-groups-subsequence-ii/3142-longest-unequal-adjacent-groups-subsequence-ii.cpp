class Solution {
public:
    // The idea is to check each of the different configuration using 'dp' while satisfying the conditions.
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        vector<string>rohit;
        vector<vector<int>>dp(n+5,vector<int>(n+2)); // Store the Hamming distance for any of the two string in words
        for(int f=0;f<n;++f)    // f-->first
        {
            for(int s=0;s<n;++s)   // s-->second
            {
                int ans=0;
                int len1=words[f].size();
                int len2=words[s].size();
                if(len1==len2)
                {
                    for(int i=0;i<len1;++i)
                    {
                        if(words[f][i]!=words[s][i]) ans++;
                    }
                }
                dp[f][s]=ans;
            }
        }
        
        vector<int>till_max(n,1),parent(n,-1);
        for(int i=0;i<n;++i)
        {
            int j=i-1;
            while(j>=0)
            {
                int len1=words[i].size();
                int len2=words[j].size();
                if(groups[j]!=groups[i] && len1==len2 && dp[i][j]==1 && till_max[i]<(1+till_max[j]))
                {
                    till_max[i]=1+till_max[j];
                    parent[i]=j;
                }
                j--;
            }
        }
        
        int mx=1,ind=0;
        for(int i=0;i<n;++i)
        {
            if(till_max[i]>mx)
            {
                mx=till_max[i];
                ind=i;
            }
        }
        
        rohit.push_back(words[ind]);
        while(parent[ind]!=-1)
        {
            rohit.push_back(words[parent[ind]]);
            ind=parent[ind];
        }
        reverse(rohit.begin(),rohit.end());
        return rohit;
    }
};