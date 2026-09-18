class Solution {
public:
    int mod = 1e9+7;
    vector<vector<int>> moves = {
        {4, 6},       // 0
        {6, 8},       // 1
        {7, 9},       // 2
        {4, 8},       // 3
        {0, 3, 9},    // 4
        {},           // 5
        {0, 1, 7},    // 6
        {2, 6},       // 7
        {1, 3},       // 8
        {2, 4}        // 9
    };
    int solve(int curr, int n, vector<vector<int>>& dp){
        if(n==1){
            return 1;  
        } 
        if(dp[n][curr]!=-1){
            return dp[n][curr]; 
        }
        long long sum = 0;
        for(auto next : moves[curr]){
            sum+=solve(next,n-1,dp);
        }
        return dp[n][curr]=sum%mod;
    }
    int knightDialer(int n) {
        vector<vector<int>> dp(n+1,vector<int>(10,-1)); 
        long long sum =0;
        for(int i = 0;i<10;i++){
            sum = sum + solve(i,n,dp);
        }
        return sum%mod;
    }
};