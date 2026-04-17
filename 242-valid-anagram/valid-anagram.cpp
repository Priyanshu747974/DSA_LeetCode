class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }

        map<char, int> mpp;

        // count characters in s
        for(int i = 0; i < s.size(); i++){
            mpp[s[i]]++;
        }

        // subtract using t
        for(int i = 0; i < t.size(); i++){
            mpp[t[i]]--;
        }

        // check if all values are 0
        for(auto it : mpp){
            if(it.second != 0){
                return false;
            }
        }

        return true;
    }
};