class Solution {
public:
    string fractionToDecimal(long long n, long long d) {
        if (n == 0) return "0";

        string res;
        if(n<0^d<0) res+='-';

        // remove sign of operands
        n = abs(n), d = abs(d);

        // append integral part
        res += to_string(n / d);

        // in case no fractional part
        if (n % d == 0) return res;

        res += '.';

        unordered_map<int, int> map;

        // simulate the division process
        for (int64_t r = n % d; r; r %= d) 
        {
            if (map.count(r) > 0) 
            {
                res.insert(map[r], 1, '(');
                res += ')';
                break;
            }
            map[r] = res.size();

            r *= 10;
            res += to_string(r / d);
        } 
        return res;
    }
};