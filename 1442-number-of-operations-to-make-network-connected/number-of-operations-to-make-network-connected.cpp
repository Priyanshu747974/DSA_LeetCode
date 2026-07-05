class DisjointSet {
    vector<int>parents, rnk;
public:
    DisjointSet(int n){
        rnk.resize(n+1,0);
        parents.resize(n+1);
        for(int i=0;i<n+1;i++){
            parents[i]=i;
        }
    }
    int findULT(int node){
        if(node==parents[node]){
            return node;        
        }
        return parents[node]=findULT(parents[node]);
    }
    void unionBYrank(int u, int v){
        int ulp_u = findULT(u);
        int ulp_v = findULT(v);

        if(ulp_u == ulp_v){
            return;
        }
        if(rnk[ulp_u] < rnk[ulp_v]){
            parents[ulp_u]=ulp_v;
        }
        else if(rnk[ulp_u] > rnk[ulp_v]){
            parents[ulp_v]=ulp_u;
        }
        else{
            parents[ulp_v]=ulp_u;
            rnk[ulp_u]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        //since edge weights are 1, MST edge sum will be n-1
        if(connections.size()<n-1){
            return -1;
        }
        DisjointSet ds(n);
        int mst=0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            if(ds.findULT(u)!=ds.findULT(v)){
                mst++;
                ds.unionBYrank(u,v);
            }
        }
        return (n-1)-mst;
    }
};

//[[1,5],[1,7],[1,2],[1,4],[3,7],[4,7],[3,5],[0,6],[0,1],[0,4],[2,6],[0,3],[0,2]]