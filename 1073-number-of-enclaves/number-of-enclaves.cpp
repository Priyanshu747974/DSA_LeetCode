class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int row,int col){
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        int dr[]={1,0,-1,0};
        int dc[]={0,-1,0,1};
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m){
                if(grid[nr][nc]==1 && !vis[nr][nc]){
                    dfs(grid,vis,nr,nc);
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int row,col;
        for(int i=0;i<m;i++){
            if(grid[0][i]==1 && vis[0][i]!=1){
                dfs(grid,vis,0,i);
            }
        }
        for(int i=0;i<m;i++){
            if(grid[n-1][i]==1 && vis[n-1][i]!=1){
                dfs(grid,vis,n-1,i);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && vis[i][0]!=1){
                dfs(grid,vis,i,0);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][m-1]==1 && vis[i][m-1]!=1){
                dfs(grid,vis,i,m-1);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]!=1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};