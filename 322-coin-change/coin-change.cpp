class Solution {
public:
    int function(int ind,vector<int>& coins, int amount,vector<vector<int>>& dp){
        if(amount==0){
            return 0;
        }
        if(ind == 0){
            if(amount%coins[ind]==0){
                return amount/coins[ind];
            }
            return 1e9;
        }
        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }
        int take = 1e9;
        if(amount >= coins[ind]){
            take =1+ function(ind,coins,amount-coins[ind],dp);
        }
        int nottake = function(ind-1, coins, amount,dp);

        return dp[ind][amount] = min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans = function(coins.size()-1,coins,amount,dp);
        if(ans>=1e9){
            return -1;
        }
        return ans;
    }
};