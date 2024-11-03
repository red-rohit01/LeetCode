class Solution {
public:
    // One of the solution can be O(n2) which is by checking each of the rotation.
    // Better solution would be to make s-->(s+s) then, we can observe that each of the possible rotation is present here 
    // as a substring in this new string. TC- O(N)
    bool rotateString(string s, string goal) {
        int orig=s.size();
        s=s+s;
        int n=s.size();
        for(int i=1;i<=(n-orig);++i)
        {
            if(s[i]==goal[0])
            {
                int j=0;
                while(j<orig && s[i+j]==goal[j]) j++;
                if(j==orig) return true;
            }
        }
        return false;
    }
};