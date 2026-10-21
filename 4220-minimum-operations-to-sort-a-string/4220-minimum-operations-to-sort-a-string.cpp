class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        char mn=s[0], mx=s[0];
        bool isSorted=true;

        for(int i=1;i<n;++i) 
        {
            if(s[i]<s[i-1]) isSorted=false;
            mn=min(mn,s[i]);
            mx=max(mx,s[i]);
        }

        if(isSorted) return 0;

        if(n==2) return -1;   // If it's not sorted and n==2 then not possible to sort it

        if(s.front()==mn || s.back()==mx) return 1;    // When first or last character is anchor

        // If mn or mx is in between array then in one operation we can send 'mn' or 'mx' to it's correct position and then use that as
        // an anchor to sort the other part in one more operation.
        for(int i=1;i<n-1;++i)
            if(s[i]==mn || s[i]==mx) return 2;

        // When mn and mx are both at the end but swapped. mx is at 0'th position and mn is at last position.
        // Then One operation make the mn inbetween and then two more operation as fall into the '2' operation case.
        return 3;
    }
};