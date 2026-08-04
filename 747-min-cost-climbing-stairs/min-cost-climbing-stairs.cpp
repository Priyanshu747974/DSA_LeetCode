class Solution {
public:
    int function(int i, vector<int>& cost, vector<int>& dp){
        if(i>=cost.size()){
            return 0 ;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int choice1 = function(i+1,cost,dp) + cost[i];
        int choice2 = function(i+2,cost,dp) + cost[i];
        return dp[i] = min(choice1 , choice2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);
        return min(function(0,cost,dp),function(1,cost,dp));
    }
};