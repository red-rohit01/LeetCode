class Solution {
public:
    // If you use cap[lower] = w; you're replacing the spot in the map with w. If you use insert, STL doesn't replace an existing key.
    // Idea is simple just check the precedence rule to return the answer.
    string toLower(string w)
    {
        for(auto &c:w) c=tolower(c);
        return w;
    }
    string unVowel(string w)
    {
        w=toLower(w);
        for(auto &c:w)
        {
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') c='#';
        }
        return w;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        int n=queries.size();
        unordered_set<string>words(wordlist.begin(),wordlist.end());
        unordered_map<string,string>cap,vowel;

        for(auto &w:wordlist)
        {
            string lower=toLower(w);
            string unvowel=unVowel(w);

            cap.insert({lower,w});
            vowel.insert({unvowel,w});
        }

        for(auto &w:queries)
        {
            if(words.find(w)!=words.end()) continue;

            string lower=toLower(w);
            string unvowel=unVowel(w);

            if(cap.find(lower)!=cap.end()) w=cap[lower];
            else if(vowel.find(unvowel)!=vowel.end()) w=vowel[unvowel];
            else w="";
        }
        return queries;
    }
};