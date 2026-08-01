class Solution {
public:
    int f(int i, int j, vector<vector<bool>>& pal,vector<vector<int>>& dp ,string& s) {

        if (i>=j)
            return 0;
        
        if(pal[i][j]){
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 1e9;

        for (int k = i; k <= j - 1; k++) {
            if(pal[i][k]){
                int cost =  f(k + 1, j,pal,dp,s) + 1;
                ans = min(ans, cost);
            }
        }

        return dp[i][j] = ans;
    }
    int minCut(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        vector<vector<bool>> pal(s.size(), vector<bool>(s.size(), false));
        for (int i = 0; i < s.size(); i++) {
            pal[i][i] = true;
        }
        for (int i = 2; i <= s.size(); i++) {
            for (int j = 0; j + i - 1 < s.size(); j++) {
                int k = j + i - 1;
                if (s[j] != s[k]) {
                    pal[j][k] = false;
                } else {
                    if (i == 2)
                        pal[j][k] = true;
                    else
                        pal[j][k] = pal[j + 1][k - 1];
                }
            }
        }
        return f(0,s.size()-1,pal,dp,s);
    }
};