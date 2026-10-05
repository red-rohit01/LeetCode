class Solution {
public:
    // When we encounter an open parenthesis '(', it means we are entering a new layer so pushed a '0'.
    // When we encounter a closed parenthesis ')', it means we are exiting the current inner layer. 

    // If the inner layer had a score of '0' (meaning it was empty, forming ()), its evaluated score becomes 1.
    // If it had a score (v>0) (meaning it contained nested elements, forming (A)), its evaluated score becomes 2*v.
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);  // The score of the current frame

        for(auto &x:s)
        {
            if(x=='(') st.push(0);
            else
            {
                int v=st.top(); st.pop();   
                int w=st.top(); st.pop();   

                st.push(w+max(2*v,1));
            }
        }
        return st.top();
    }
};