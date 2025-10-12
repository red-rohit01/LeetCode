class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) 
    {
        long long result=0;
        map<pair<int, int>,int> freq;   // Storing pair instead of division to care for precision in division

        for (auto& rect : rectangles)
        {
            int gcd = __gcd(rect[0], rect[1]);
            pair<int, int> key = {rect[0]/gcd, rect[1]/gcd};
            if(freq.find(key)!=freq.end()) result+=freq[key];
            freq[key]++;
        }

        return result;
    }
};