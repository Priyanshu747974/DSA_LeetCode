class Solution {
public:
    bool solve(int i, string &s, unordered_set<string> &st,vector<int> & dp) {
        if (i == s.size()) {
            return true;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        for (int j = i; j < s.size(); j++) {
            string n(s.begin()+i,s.begin()+j+1);
            if(st.count(n)){
                if(solve(j+1,s,st,dp)){
                    return dp[i]=true;
                }
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        vector<int> dp(s.size(),-1);
        for (int i = 0; i < wordDict.size(); i++) {
            st.insert(wordDict[i]);
        }
        return solve(0,s,st,dp);
    }
};