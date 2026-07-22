class Solution {
public:
    int function( int left , int right, string & s,vector<vector<int>>& dp){
        if(left>right){
            return 0;
        }
        if(left == right){
            return 1;
        }
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        if(s[left]==s[right]){
            return dp[left][right]= 2+function(left+1, right-1, s,dp);
        }
        return dp[left][right]= max(function(left+1,right,s,dp),function(left,right-1,s,dp));
    }
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        return function(0,s.size()-1,s,dp);
    }
};