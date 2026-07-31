class Solution {
public:
    // Count Frequencies: Count how many times each letter appears in the word using a fixed-size array of size 26.
    // Sort: Sort these counts so we know which letters appear the most.
    // Greedy Assignment: Process the most frequent letters first. We use a math trick (25 - i) / 8 + 1 to figure out the push cost:
    // The top 8 most frequent letters cost 1 push.
    // The next 8 cost 2 pushes.
    // The next 8 cost 3 pushes, and so on.
    int minimumPushes(string word) {
        vector<int>freq(26);
        for(auto &x:word) freq[x-'a']++;

        sort(freq.begin(),freq.end());
        int ans=0;

        for(int i=25;i>=0 && freq[i]>0;--i) ans+=freq[i]*((25-i)/8 +1);

        return ans;
    }
};