class Solution {
public:
    int function(int i, int j,string & s, string &t,vector<vector<int>>& dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
            return dp[i][j]=1+function(i-1,j-1,s,t,dp);
        }
        return  dp[i][j]=max(function(i-1,j,s,t,dp),function(i,j-1,s,t,dp));
    }
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        int lcs = function(s.size()-1,t.size()-1,s,t,dp);
        if(lcs == s.size()){
            return true;
        }
        return false;
    }
};