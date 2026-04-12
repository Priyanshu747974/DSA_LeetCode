class Solution {
public:
    vector<string> ans;
    void function(int i,vector<string>&candidates,string curr,string& digits){
        if(i==digits.size()){
            ans.push_back(curr);
            return;
        }
        string letters=candidates[digits[i]-'0'];
        for(char ch: letters){
            function(i+1,candidates,curr+ch,digits);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return {};
        vector<string> candidates = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        function(0,candidates,"",digits);
        return ans;
    }
};