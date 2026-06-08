class Solution {
public: 
    void dfs(vector<vector<char>>& board, vector<vector<int>>& vis,int row,int col){
        vis[row][col]=1;
        int n=board.size();
        int m=board[0].size();
        int dr[]={1,0,-1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m){
                if(board[nr][nc]=='O' && !vis[nr][nc]){
                    dfs(board,vis,nr,nc);
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<char>> mybo(n,vector<char>(m,'O'));
            for(int i=0;i<m;i++){
                if(board[0][i]=='O' && !vis[0][i]){
                    dfs(board,vis,0,i);
                }
            }
            for(int i=0;i<m;i++){
                if(board[n-1][i]=='O' && !vis[n-1][i]){
                    dfs(board,vis,n-1,i);
                }
            }
            for(int i=0;i<n;i++){
                if(board[i][0]=='O' && !vis[i][0]){
                    dfs(board,vis,i,0);
                }
            }
            for(int i=0;i<n;i++){
                if(board[i][m-1]=='O' && !vis[i][m-1]){
                    dfs(board,vis,i,m-1);
                }
            }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && vis[i][j]!=1){
                    mybo[i][j]='X';
                }
                else{
                    mybo[i][j]=board[i][j];
                }
            }
        }
        board=mybo;
    }
};