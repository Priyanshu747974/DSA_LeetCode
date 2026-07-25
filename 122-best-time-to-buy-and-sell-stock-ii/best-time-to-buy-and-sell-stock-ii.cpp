class Solution {
public:
    int function(int i,int canbuy, vector<int>& prices, vector<vector<int>>& dp){
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][canbuy]!=-1){
            return dp[i][canbuy];
        }
        if(canbuy==1){
            return dp[i][canbuy] = max(-prices[i] + function(i + 1, 0, prices, dp),function(i + 1, 1, prices, dp));
        }
        else{
            return dp[i][canbuy] = max(prices[i] + function(i + 1, 1, prices, dp),function(i + 1, 0, prices, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp (prices.size()+1,vector<int>(2,-1));
        for(int i=0;i<2;i++){
            dp[prices.size()][i]=0;
        }
        for(int i=prices.size()-1;i>=0;i--){
            for(int canbuy=0;canbuy<2;canbuy++){
                if(canbuy==1){
                    dp[i][canbuy] = max(-prices[i] + dp[i + 1][0],dp[i + 1][1]);
                }
                else{
                    dp[i][canbuy] = max(prices[i] + dp[i + 1][1],dp[i + 1][0]);
                }
            }
        }
        return dp[0][1];
    }
};