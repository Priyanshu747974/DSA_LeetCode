class Solution {
public:
    int mod = 1e9+7;
    vector<vector<int>> rules = {
        {1},         //a
        {0,2},       //e
        {0,1,3,4},   //i
        {2,4},       //o
        {0}          //u
    };
    int solve(int n,int curr,vector<vector<int>>& dp){
        if(n==1){
            return 1;
        }
        long long sum =0;
        if(dp[n][curr]!=-1){
            return dp[n][curr];
        }
        for(auto next : rules[curr]){
            sum += solve(n-1,next,dp);
        }
        return dp[n][curr]=sum%mod;
    }
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n+1,vector<int>(5,-1));
        
        long long sum = 0;
        for(int i = 0;i<5;i++){
            sum+=solve(n,i,dp);
            sum%= mod;
        }
        return sum;
    }
};