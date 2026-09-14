class Solution {
public:
    void solve(int i, string &s,string &curr, unordered_set<string> &st,vector<string> &ans) {
        if (i == s.size()) {
            ans.push_back(curr);
            return;
        }
        for (int j = i; j < s.size(); j++) {
            string n(s.begin()+i,s.begin()+j+1);
            if(st.count(n)){
                string temp = curr;
                if(!curr.empty()){
                    curr+=" ";
                }
                curr+=n;
                solve(j+1,s,curr,st,ans);
                curr = temp;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        vector<string> ans;
        for (int i = 0; i < wordDict.size(); i++) {
            st.insert(wordDict[i]);
        }
        string curr = "";
        solve(0,s,curr,st,ans);
        return ans;
    }
};