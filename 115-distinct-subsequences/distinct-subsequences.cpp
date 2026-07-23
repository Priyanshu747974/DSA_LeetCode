class Solution {
public:
    long long function(int ind1, int ind2, string& s, string& t, vector<vector<long long>>& dp){
        if(ind2<0){
            return 1;
        }
        if(ind1<0){
            return 0;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        if(s[ind1]==t[ind2]){
            return dp[ind1][ind2] = function(ind1-1,ind2-1,s,t,dp) + function(ind1-1,ind2,s,t,dp);
        }
        return  dp[ind1][ind2]=function(ind1-1,ind2,s,t,dp);
    }
    int numDistinct(string s, string t) {
        vector<vector<long long>> dp(s.size(),vector<long long>(t.size(),-1));
        return function(s.size()-1,t.size()-1,s,t,dp);
    }
};