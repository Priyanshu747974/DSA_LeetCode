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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int components=n;
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1] == stones[j][1]){
                    int ui = ds.findULT(i);
                    int uj = ds.findULT(j);
                    if(ui==uj){
                        continue;
                    }
                    ds.unionBYrank(i,j);
                    components--;
                }
            }
        }
        return n-components;
    }
};
