class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> mpp;
        int i =0;
        int j =0;
        int ans = j-i;
        while(j<s.size() && i<=j){
            mpp[s[j]]++;
            while(mpp[s[j]]>2){
                mpp[s[i]]--;
                i++;
            }
            j++;
            ans= max(j-i,ans);
        }
        return ans;
    }
};