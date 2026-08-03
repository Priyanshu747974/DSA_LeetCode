class Solution {
public:
    long long function(int i, vector<int>& stoneValue, vector<long long>& dp,  vector<bool>& vis){
        if( i >= stoneValue.size()){
            return 0;
        }
        if(vis[i]){
            return dp[i];
        }
        long long take1 = stoneValue[i]-function(i+1,stoneValue,dp,vis);
        long long take2 = LLONG_MIN;
        long long take3 = LLONG_MIN;
        if(i+1<stoneValue.size()){
            take2 = stoneValue[i]+stoneValue[i+1]-function(i+2,stoneValue, dp,vis);
        }
        if(i+2<stoneValue.size()){
            take3 = stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-function(i+3,stoneValue, dp,vis);
        }

        dp[i] = max(take1, max(take2,take3));
        vis[i] = true;
        return dp[i];
    }
    string stoneGameIII(vector<int>& stoneValue) {
        vector<bool> vis(stoneValue.size(),false);
        vector<long long> dp(stoneValue.size(),1e9);
        long long ans = function(0,stoneValue,dp,vis);
        if(ans>0){
            return "Alice";
        }
        else if(ans == 0){
            return "Tie";
        }
        else{
            return "Bob";
        }
    }
};