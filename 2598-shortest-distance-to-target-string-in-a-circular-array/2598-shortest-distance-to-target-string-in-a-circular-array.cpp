class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        if(find(words.begin(),words.end(),target)==words.end()) return -1;
        
        int ans1=0;
        int i=startIndex;
        while(1)
        {
            if(words[i]==target)
            {
                break;
            }
            i=(i+1)%n;
            ans1++;
        }
        int ans2=0;
        i=startIndex;
        while(1)
        {
            if(words[i]==target)
            {
                break;
            }
            i=(i-1+n)%n;
            ans2++;
        }
        return min(ans1,ans2);
    }
};