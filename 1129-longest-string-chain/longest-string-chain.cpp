    bool comp(string & s1, string & s2){
        return s1.size()<s2.size();
    }
class Solution {
public:
    bool check(string & s1, string & s2){
        if(s1.size()!=s2.size()+1){
            return false;
        }
        int i = 0;
        int j = 0;
        while(i<s1.size() && j<s2.size()){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }    
        return j == s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int maxi = 1;
        sort(words.begin(), words.end(),comp);
        vector<int> dp(words.size(), 1);
        for (int ind = 0; ind < words.size(); ind++) {
            for (int prev = 0; prev < ind; prev++) {
                if (check(words[ind], words[prev]) && dp[ind] < 1 + dp[prev]) {
                    dp[ind]=1+dp[prev];
                }
            }
            maxi = max(maxi,dp[ind]);
        }
        return maxi;
    }
};