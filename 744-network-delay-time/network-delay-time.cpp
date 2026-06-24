class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<pair<int,int>> adj[n+1];
        int src=k;

        for(auto edge : times){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v,w});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int>dist(n+1,1e9);

        dist[src]=0;
        pq.push({0,src});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int time= it.first;
            int node= it.second;

            for(auto it: adj[node]){
                int nnode=it.first;
                int ntime=it.second;
                if(time+ ntime<dist[nnode]){
                    dist[nnode]=time+ntime;
                    pq.push({dist[nnode],nnode});
                }
                
            }
        }
        int maxi = INT_MIN;
        for(int i=1;i<=n;i++){
            maxi=max(maxi,dist[i]);
            if(dist[i]==1e9){
                return -1;
            }
        }
        return maxi;
    }
};