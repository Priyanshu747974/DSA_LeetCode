#include <string>
#include <algorithm>

class Solution {
public:
    int splitNum(int num) {
       
        std::string s = std::to_string(num);
        std::sort(s.begin(), s.end());
        
        int num1 = 0;
        int num2 = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            int digit = s[i] - '0';
            if (i % 2 == 0) {
                num1 = num1 * 10 + digit;
            } else {
                num2 = num2 * 10 + digit;
            }
        }
        
        return num1 + num2;
    }
};