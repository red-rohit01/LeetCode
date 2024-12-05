class Solution {
public:
    bool canChange(string start, string target) {
        int n=start.size();
        int st=0,en=0;

        while(st<n || en<n)
        {
            while(st<n && start[st]=='_') st++;

            while(en<n && target[en]=='_') en++;

            if((st==n) || (en==n))
            {
                return (st==n && en==n);     // Both the index should reach end position.
            }

            if((start[st]!=target[en]) || (start[st]=='L'  && st<en) || (start[st]=='R' && st>en)) return false;

            st++;
            en++;
        }
        return true;
    }
};