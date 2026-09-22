class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1);
        vector<int> outdegree(n+1);
        for(int i=0;i<trust.size();i++){
            indegree[trust[i][1]]++;
            outdegree[trust[i][0]]++;
        }
        int i=1;
        int ans = -1;
        while(i < n+1){
            if(indegree[i]==n-1 && outdegree[i]==0){
                ans = i;
            }
            i++;
        }
        return ans;
    }
};