class Solution {
public:
    int numSplits(string s) {
        map<char, int> left, right;

        for(char c : s)
            right[c]++;

        int cnt = 0;

        for(int i = 0; i < s.size() - 1; i++) {
            left[s[i]]++;
            right[s[i]]--;

            if(right[s[i]] == 0)
                right.erase(s[i]);

            if(left.size() == right.size())
                cnt++;
        }

        return cnt;
    }
};