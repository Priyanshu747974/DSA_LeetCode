class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n= heights.size();
        int m= heights[0].size();
        pair<int,int> start= {0,0};
        pair<int,int> end= {n-1,m-1};

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        vector<vector<int>> efforts(n,vector<int>(m,1e9));

        q.push({0,{start.first,start.second}});
        efforts[start.first][start.second]=0;

        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};

        while(!q.empty()){
            auto it = q.top();
            q.pop();
            int effort= it.first;
            int r = it.second.first;
            int c = it.second.second;

            if(r==n-1 && c== m-1){
                return effort;
            }
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int newEffort = max(abs(heights[nr][nc]-heights[r][c]),effort);
                    if(newEffort<efforts[nr][nc]){
                        efforts[nr][nc]=newEffort;
                        q.push({newEffort,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};