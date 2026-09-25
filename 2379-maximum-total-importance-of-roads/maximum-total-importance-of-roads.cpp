class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<int, int> mpp;
        for(auto it : roads){
            mpp[it[0]]++;
            mpp[it[1]]++;
        }
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({i,mpp[i]});            
        }
        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return a.second < b.second;
        });
        vector<int> importance(n);

        for(int i = 0; i < n; i++){
            importance[v[i].first] = i + 1;
        }

        long long ans = 0;

        for(auto it : roads){
            ans += importance[it[0]];
            ans += importance[it[1]];
        }

        return ans;
    }
};