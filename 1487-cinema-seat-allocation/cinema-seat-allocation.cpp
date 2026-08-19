class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        int ans = 2 * n;

        map<int, vector<int>> mpp;

        for (auto it : reservedSeats) {
            mpp[it[0]].push_back(it[1]);
        }

        for (auto& it : mpp) {

            int p1 = 0;
            int p2 = 0;
            int p3 = 0;

            for (auto seat : it.second) {

                if (seat >= 2 && seat <= 5)
                    p1 = 1;

                if (seat >= 4 && seat <= 7)
                    p2 = 1;

                if (seat >= 6 && seat <= 9)
                    p3 = 1;
            }

            if (p1 == 0 && p3 == 0) {
                // 2 families → nothing to subtract
                continue;
            }
            else if (p1 == 0 || p2 == 0 || p3 == 0) {
                // 1 family possible
                ans--;
            }
            else {
                // 0 families possible
                ans -= 2;
            }
        }

        return ans;
    }
};