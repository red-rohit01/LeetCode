class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int l=0,h=n-1,mid;
        while (l <= h) 
        {
            mid = (l + h) / 2;
            if (letters[mid] <= target) 
            {
                l = mid + 1;
            } 
            else 
            {
                h = mid - 1;
            }
        }
        return l == letters.size() ? letters[0] : letters[l];
    }
};