class Solution {
public:
    int function(int ind,vector<int>& coins, int amount,vector<vector<int>>& dp){
        if(amount==0){
            return 0;
        }
        if(ind == 0){
            if(amount%coins[0]==0){
                return amount/coins[0];
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
        for(int i = 0;i<coins.size();i++){
            dp[i][0]=0;
        }
        for(int amt=0;amt<amount+1;amt++){
            if(amt%coins[0]==0){
                dp[0][amt]=amt/coins[0];
            }
            else{
                dp[0][amt] = 1e9;
            }
        }
        for(int ind = 1;ind<coins.size();ind++){
            for(int amt=1;amt<=amount;amt++){
                int take = 1e9;
                if(amt >= coins[ind]){
                    take =1+ dp[ind][amt-coins[ind]];
                }
                int nottake = dp[ind-1][amt];
                dp[ind][amt]= min(take,nottake);
            }
        }
        if (dp[coins.size()-1][amount] >= 1e9){
            return -1;
        }
        return dp[coins.size()-1][amount];
    }
};