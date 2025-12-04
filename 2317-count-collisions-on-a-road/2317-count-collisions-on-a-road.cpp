class Solution {
public:
    int countCollisions(string directions) {
        int ans=0;
        int n=directions.size();
        stack<char>st;
        for(int i=0;i<n;++i)
        {
            if(directions[i]=='L')
            {
                if(st.size()>0 && st.top()=='R') 
                {
                    st.pop();
                    ans+=2;
                    st.push('S');
                }
                else if(st.size()>0 && st.top()=='S')
                {
                    ans++;
                }
            }
            else st.push(directions[i]);
        }

        while(st.size()>0 && st.top()=='R')
        {
            st.pop();
        }
        while(st.size()>0)
        {
            if(st.top()=='R') ans++;
            st.pop();
        }
        return ans;
    }
};