class Solution {
public:
    int remove(string &s,string target,int points)
    {
        int n=s.size();
        int curr=0;
        int w_index=0; //We'll try to simulate stack functionality with this
        for(int r_index=0;r_index<n;++r_index)
        {
            s[w_index++]=s[r_index];
            if(w_index>1 && s[w_index-2]==target[0] && s[w_index-1]==target[1])
            {
                w_index-=2;
                curr+=points;
            }
        }
        // cout<<s<<" "<<w_index<<" ";
        s.erase(s.begin()+w_index,s.end());
        return curr;
    }
    int maximumGain(string s, int x, int y) {
        int ans=0;
        if(x>=y)
        {
            ans+=remove(s,"ab",x);               //First remove the higher yielding points
            ans+=remove(s,"ba",y);              // Now remove the other 
        }
        else
        {
            ans+=remove(s,"ba",y);
            ans+=remove(s,"ab",x);
        }
        return ans;
    }
};