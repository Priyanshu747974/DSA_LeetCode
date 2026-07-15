class Solution {
public:
    int function(int ind,int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(amount == 0){
            return 1;
        }
        if(ind == 0){
            if(amount%coins[0] == 0){
                return 1;
            }
            return 0;
        }
        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }
        int take = 0;
        if(amount>=coins[ind]){
            take = function(ind,amount-coins[ind],coins,dp);
        }
        int nottake = function(ind-1,amount,coins,dp);

        return dp[ind][amount]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return function(coins.size()-1,amount,coins,dp);
    }
};