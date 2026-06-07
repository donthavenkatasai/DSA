class Solution {
public:
    bool isNumber(string s) {
        bool hasDigit = false;
        bool hasDot = false;
        bool hasExp = false;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                hasDigit = true;
            }
            else if (c == '+' || c == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else if (c == '.') {
                if (hasDot || hasExp)
                    return false;
                hasDot = true;
            }
            else if (c == 'e' || c == 'E') {
                if (hasExp || !hasDigit)
                    return false;

                hasExp = true;
                hasDigit = false; // need digits after exponent
            }
            else {
                return false;
            }
        }

        return hasDigit;
    }
};