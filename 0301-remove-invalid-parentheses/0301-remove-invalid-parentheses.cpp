class Solution {
public:
    unordered_set<string>ans;
    void helper(string& s,int &n,int& removal,int temp,int ind,string &curr)
    {
        if(ind==n)
        {
            if(temp==removal)
            {
                int cnt=0;
                for(int i=0;i<curr.size();++i)
                {
                    if(curr[i]=='(') cnt++;
                    else if(curr[i]==')') cnt--;

                    if(cnt<0) return;
                }
                if(cnt>0) return;
                ans.insert(curr);
            }
            return ;
        }

        // Always keep letters
        if(s[ind]>='a' && s[ind]<='z')
        {
            curr.push_back(s[ind]);
            helper(s,n,removal,temp,ind+1,curr);
            curr.pop_back();
        }
        else
        {
            // Keep the parenthesis
            curr.push_back(s[ind]);
            helper(s,n,removal,temp,ind+1,curr);
            curr.pop_back();

            // Remove the parenthesis if removals remain
            if(temp<removal) helper(s, n, removal, temp + 1, ind + 1, curr);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        ans.clear();
        int removal=0;
        int val=0;
        int n=s.size();
        for(int i=0;i<n;++i)
        {
            if(s[i]==')') val--;
            else if(s[i]=='(') val++;

            if(val<0) 
            {
                removal++;
                val++;
            }
        }
        if(val>0) removal+=val;
        if(removal==0) return {s};

        string curr="";
        helper(s,n,removal,0,0,curr);
        vector<string>res(ans.begin(),ans.end());
        return res;
    }
};