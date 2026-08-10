class Solution {
public:
    int function(int i,vector<int>& dp){
        if(i==0){
            return 0;
        }
        if(i==1 || i==2){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int current = function(i-1,dp)+function(i-2,dp)+function(i-3,dp);
        return dp[i]=current;
    }
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        return function(n,dp);
    }
};