class Solution {
public:
    int mod = 1e9+7;
    int solve(int n, vector<int>& dp){

        if(n==0)return 1;
        if(n==1)return 1;
        if(n==2)return 2;

        if(dp[n]!=-1){
            return dp[n];
        }
        long long sum = 2LL*solve(n-1,dp)+solve(n-3,dp);
        return dp[n]=sum% mod;
    }
    int numTilings(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};