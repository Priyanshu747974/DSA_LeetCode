class Solution {
public:
    int sum(int n, int ans) {
        int i = 2;
        bool found = false;
        while (i < n/2) {
            if (n % i == 0) {
                n = n / i;
                ans += i;
                found = true;
            } else {
                i++;
            }
        }

        if (!found) {
            return n;
        }
        ans += n;

        return sum(ans, 0);
    }
    int smallestValue(int n) { return sum(n, 0); }
};