class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        vector<pair<int,int>> v;

        for(int i = 0; i < values.size(); i++)
            v.push_back({values[i], labels[i]});

        sort(v.rbegin(), v.rend());

        unordered_map<int,int> mpp;
        int sum = 0, cnt = 0;

        for(auto p : v) {
            int val = p.first;
            int label = p.second;

            if(mpp[label] < useLimit) {
                sum += val;
                mpp[label]++;
                cnt++;
            }

            if(cnt == numWanted)
                break;
        }

        return sum;
    }
};