class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        long long direct = 0;

        for (int i = 0; i < arr.size(); i++) {
            direct += abs((long long)arr[i] - brr[i]);
        }

        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());

        long long rearrange = k;

        for (int i = 0; i < arr.size(); i++) {
            rearrange += abs((long long)arr[i] - brr[i]);
        }

        return min(direct, rearrange);
    }
};