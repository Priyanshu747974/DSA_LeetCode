class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        int src =0;
        const int MOD = 1e9 + 7;
        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            int t = it[2];

            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }
        priority_queue<
                pair<long long,int>,
                vector<pair<long long,int>>,
                greater<pair<long long,int>>
                > pq;
        vector<long long> dist(n,LLONG_MAX);
        vector<long long> ways(n);
        
        dist[src]=0;
        ways[src]=1;
        pq.push({0,src});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long dis = it.first;
            int node = it.second;

            if(dis > dist[node]) continue;

            for(auto it : adj[node]){
                int nnode = it.first;
                long long ndis = it.second;

                long long newdist = ndis+dis;
                if(newdist<dist[nnode]){
                    dist[nnode]=newdist;
                    ways[nnode]=ways[node];
                    pq.push({dist[nnode],nnode});
                }
                else if(newdist == dist[nnode]){
                    ways[nnode] = (ways[nnode] + ways[node]) % MOD;
                }
            }
        }
        return (int)(ways[n-1] % MOD);
    }
};