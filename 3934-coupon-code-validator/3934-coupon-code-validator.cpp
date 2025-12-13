class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n=code.size();

        unordered_map<string, int> businessLineSortOrder = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        // Store each valid coupon with the information needed for sorting
        // First field: (business line order, code), Second field: code string
        vector<pair<pair<int, string>, string>>sortableCoupons;

        for (int i=0;i<n;++i) 
        {
            if (!isActive[i]) continue;

            if (businessLineSortOrder.find(businessLine[i]) == businessLineSortOrder.end()) continue;

            if (code[i].empty()) continue; //""

            bool isCodeValid=true;

            for(char c:code[i]) 
            {
                if (!(isalnum(c) || c == '_')) {
                    isCodeValid = false;
                    break;
                }
            }
            if (!isCodeValid) continue;

            // Everything is valid, collect coupon for sorting
            int sortIndex = businessLineSortOrder[businessLine[i]];
            sortableCoupons.push_back({{sortIndex, code[i]}, code[i]});
        }

        // Sort by business line order, then code alphabetically
        sort(sortableCoupons.begin(), sortableCoupons.end());

        vector<string> sortedValidCodes;
        for (auto& entry:sortableCoupons) sortedValidCodes.push_back(entry.second);

        return sortedValidCodes;
    }
};