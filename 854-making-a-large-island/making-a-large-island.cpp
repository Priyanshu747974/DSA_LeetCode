class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findULT(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findULT(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findULT(u);
        int pv = findULT(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        DisjointSet ds(n * n);

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Step 1: Connect all adjacent land cells
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {

                if (grid[row][col] == 0)
                    continue;

                for (int k = 0; k < 4; k++) {
                    int nr = row + dr[k];
                    int nc = col + dc[k];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {

                        int u = row * n + col;
                        int v = nr * n + nc;

                        ds.unionBySize(u, v);
                    }
                }
            }
        }

        int ans = 0;

        // Step 2: Try converting every 0 into 1
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {

                if (grid[row][col] == 1)
                    continue;

                unordered_set<int> components;

                for (int k = 0; k < 4; k++) {
                    int nr = row + dr[k];
                    int nc = col + dc[k];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {

                        int node = nr * n + nc;
                        components.insert(ds.findULT(node));
                    }
                }

                int total = 1;

                for (int parent : components) {
                    total += ds.size[parent];
                }

                ans = max(ans, total);
            }
        }

        // Step 3: Handle case when grid already has all 1s
        for (int i = 0; i < n * n; i++) {
            if (ds.findULT(i) == i) {
                ans = max(ans, ds.size[i]);
            }
        }

        return ans;
    }
};