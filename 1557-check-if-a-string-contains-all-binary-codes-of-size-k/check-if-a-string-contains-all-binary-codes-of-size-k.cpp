class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map<string,int> mpp;
        for(int i = 0; i + k <= s.size(); i++) {
            mpp[s.substr(i, k)]++;
        }
        int ans = 1<<k;
        if(mpp.size()>=ans){
            return true;
        }

        return false;
    }
};