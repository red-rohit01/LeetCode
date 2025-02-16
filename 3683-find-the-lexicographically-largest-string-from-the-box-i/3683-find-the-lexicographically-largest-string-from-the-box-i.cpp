class Solution {
public:
    string answerString(string word, int numFriends) {
        
        //if we have only one friend then no need to split
        if(numFriends == 1) return word;

        int n = word.size(); 

        int i=0; // start index

        int sz=n-(numFriends-1); // So that we have a window
        // only upto that particular index (j).
        // Say we have "dbca" and we start from 0 with a goal to split in 2 friends i.e 1 split, 
        // then the j will be uptil 3. that is, in one go if we take 
        // three characters together ("dbc") then a single character will be left.
        // and it would be satisfying the constraint of numFriends splits - "dbc" & "a"
        // else it won't be possible
        // as the loop moves, the window moves
        // "dbc", "bca", "ca", "a".
        
        string ans=""; // empty string to store the final answer

        while(i<=n) // to generate all the split words and get the max of them
        {
            string temp = "";

            for(int k=i;k<min(n,i+sz);++k) temp+=word[k];

            ans=max(ans,temp); 
            ++i;
        }
        return ans;
    }
};