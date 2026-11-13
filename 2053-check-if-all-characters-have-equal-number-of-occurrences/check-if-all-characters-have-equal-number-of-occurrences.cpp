class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int n = s.length();
        map<char,int> mpp;
        for(int i =0;i<n;i++){
            mpp[s[i]]++;
            }
        int freq = mpp.begin()->second;

        for(auto it : mpp){
            if(it.second != freq){
                return false;
            }
        }

        return true;
    }
};