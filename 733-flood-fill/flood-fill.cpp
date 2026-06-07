class Solution {
public:
    void dfs(vector<vector<int>> & image,vector<vector<int>>& vis, int r,int c, int color, int og){
        vis[r][c]=1;
        image[r][c]=color;
        int n=image.size();
        int m=image[0].size();
        int dr[]={1,0,-1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr= r+ dr[i];
            int nc= c+ dc[i];
            
            if(nr>=0 && nr<n && nc>=0 && nc<m){
                if(image[nr][nc]==og && vis[nr][nc]!=1){
                    dfs(image,vis,nr,nc,color,og);
                    image[nr][nc]=color;
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans=image;
        int og= image[sr][sc];
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        dfs(ans,vis,sr,sc,color,og);
        return ans;
    }
};