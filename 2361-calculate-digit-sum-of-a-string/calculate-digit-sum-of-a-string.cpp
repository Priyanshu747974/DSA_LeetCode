class Solution {
public:
    string function(string s, int k) {
        if (s.length() <= k) {
            return s;
        }
        string newStr = "";
        int i = 0;
        int j = k - 1;
        int sum = 0;
        while (i < s.length()) {
            sum += s[i] - '0';
            if (i == j || i == s.length() - 1) {
                newStr += to_string(sum);
                sum = 0;
                j += k;
            }

            i++;
        }
        return function(newStr, k);
    }
    string digitSum(string s, int k) {
         return function(s, k);
    }
};