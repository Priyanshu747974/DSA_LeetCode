class Solution {
public:
    bool isPalindrome(string & s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int function(int i, int j, string& s, vector<vector<int>>& dp) {
        if (i>=j)
            return 0;

        if(isPalindrome(s,i,j)){
            return 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 1e9;

        for (int k = i; k < j; k++) {
            if(isPalindrome(s,i,k)){
                int cost = function(k + 1, j,s,dp) + 1;
                ans = min(ans, cost);
            }
            
        }

        return dp[i][j] = ans;
    }
    int minCut(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        return function(0,s.size()-1,s,dp);
    }
};