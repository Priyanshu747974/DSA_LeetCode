class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> mpp;
        int i =0;
        int j =0;
        int ans = j-i+1;
        while(j<s.size() && i<=j){
            mpp[s[j]]++;
            while(mpp[s[j]]>2){
                mpp[s[i]]--;
                i++;
            }
            ans= max(j-i+1,ans);
            j++;
        }
        return ans;
    }
};