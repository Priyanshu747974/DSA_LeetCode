class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        vector<char> s1;
        for(int i = 0;i<n;i++){
            s1.push_back('.');
        } 
        vector<char> s2;
        for(int i = 0;i<n-1;i++){
            s2.push_back('#');
        } 
        s2.push_back('.');

        string a;
        for(int i = 0;i<n;i++){
            a.push_back(s1[i]);
        }
        string b;
        for(int i = 0;i<n;i++){
            b.push_back(s2[i]);
        }
        ans.push_back(a);
        if(m>1){
            for(int i = 1;i<m;i++){
                ans.push_back(b);
            }
        }
        return ans;
    }
};