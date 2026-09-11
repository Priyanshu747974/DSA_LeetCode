class Solution {
public:
    vector<int> threedigit(vector<int> digits, vector<int>& ans) {
        for (int i = 0; i < digits.size(); i++) {
            if(digits[i]==0){
                continue;
            }
            for (int j = 0; j < digits.size(); j++) {
                for (int k = 0; k < digits.size(); k++) {
                    if(i == j || i == k || j == k)continue;
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
    int totalNumbers(vector<int>& digits) {
        vector<int> ans;
        threedigit(digits,ans);
        unordered_set<int> st;
        for(int i =0;i<ans.size();i++){
            if(ans[i]%2==0){
                st.insert(ans[i]);
            }
        }
        return st.size();
    }
};