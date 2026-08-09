class Solution {
public:
    int function(int i, int m, vector<int>& piles,vector<vector<int>>& dp) {
        int total=0;
        for(int ind = i;ind<piles.size();ind++){
            total += piles[ind];
        }
        int ans =0;
        if (piles.size() == 0) {
            return 0;
        }
        if (i >= piles.size()) {
            return 0;
        }
        if(dp[i][m]!=-1){
            return dp[i][m];
        }
        
        for (int x = 1; x <= 2*m; x++) {
            int newm = max(x, m);
            int opponent = function(x + i, newm, piles,dp);
            int current = total-opponent;
            ans=max(current,ans);
        }
        return dp[i][m]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(),vector<int>(2*piles.size(),-1));
        return function(0,1,piles,dp);
    }
};