class Solution {
public: 
    int function(int left, int right,string & s,vector<vector<int>>& dp){
        if(left>right){
            return 0;
        }
        if(left==right){
            return 0;
        }
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        if(s[left]==s[right]){
            return dp[left][right]= function(left+1,right-1,s,dp);
        }
        else{
            return dp[left][right] = 1+min(function(left+1,right,s,dp),function(left,right-1,s,dp));
        }
    }
    int minInsertions(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),0));
        for(int i=0;i<s.size();i++){
            dp[i][i]=0;
        }
        for(int left=s.size()-1;left>=0;left--){
            for(int right=left+1;right<s.size();right++){
                if(s[left]==s[right]){
                    dp[left][right]= dp[left+1][right-1];
                }
                else{
                    dp[left][right] = 1+min(dp[left+1][right],dp[left][right-1]);
                }
            }
        }
        return dp[0][s.size()-1];
    }
};