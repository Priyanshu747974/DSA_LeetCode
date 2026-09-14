class Solution {
public:
    bool solve(int i, int j,int k, string & s1, string &s2, string &s3, vector<vector<int>> &dp){
        if(k==s3.size() && i==s1.size() && j==s2.size()){
            return true;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool takes1 = false;
        bool takes2 = false;
        if(k < s3.size() && i < s1.size() && s3[k] == s1[i]){
            takes1 = solve(i+1,j,k+1,s1,s2,s3,dp);
        }
        if(k < s3.size() && j<s2.size() && s3[k]==s2[j]){
            takes2 = solve(i,j+1,k+1,s1,s2,s3,dp);
        }
        return dp[i][j]=takes1||takes2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()){
            return false;
        }
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return solve(0,0,0,s1,s2,s3,dp);
    }
};