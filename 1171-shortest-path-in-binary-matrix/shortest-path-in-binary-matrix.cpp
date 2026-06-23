class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n =grid.size();
        int m =grid[0].size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1){
            return -1;
        }
        if (n == 1){
            return 1;
        }
        pair<int,int> start={0,0};
        pair<int,int> end={n-1,m-1};

        vector<vector<int>>dist(n,vector<int>(m,1e9));
        queue<pair<int,pair<int,int>>> q;

        dist[start.first][start.second]=1;
        q.push({1,{start.first,start.second}});

        int dr[]={0,1,0,-1,1,1,-1,-1};
        int dc[]={1,0,-1,0,1,-1,1,-1};

        while(!q.empty()){
            auto it =q.front();
            q.pop();
            int dis=it.first;
            int r=it.second.first;
            int c=it.second.second;

            for(int i=0;i<8;i++){
                int nr= r+dr[i];
                int nc= c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0){
                    if(dis+1 < dist[nr][nc]){
                        dist[nr][nc]=dis+1;
                        if(nr== end.first && nc==end.second){
                            return dist[nr][nc];
                        }
                        q.push({dist[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};