class Solution {
public:
    void dfs(vector<vector<char>> & grid,vector<vector<int>>& vis,int row, int col){
        vis[row][col]=1;
        int n= grid.size();
        int m= grid[0].size();
        int dr[]={1,0,-1,0};
        int dc[]={0,1,0,-1};
        
        for(int i=0;i<4;i++){
            int nr= row+dr[i];
            int nc= col+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m){
                if(grid[nr][nc]=='1' && vis[nr][nc]!=1){
                    dfs(grid,vis,nr,nc);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]!=1){
                    cnt++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return cnt;
    }
};