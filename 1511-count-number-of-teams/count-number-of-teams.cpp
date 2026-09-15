class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        for(int i=0;i<rating.size();i++){
            int rightsmall =0;
            int rightlarge =0;
            int leftsmall =0;
            int leftlarge =0;
            for(int j =0;j<i;j++){
                if(rating[i]<rating[j]){
                    leftlarge++;
                }
                if(rating[i]>rating[j]){
                    leftsmall++;
                }
            }
            for(int j =i+1;j<rating.size();j++){
                if(rating[i]<rating[j]){
                    rightlarge++;
                }
                if(rating[i]>rating[j]){
                    rightsmall++;
                }
            }
            ans+= leftsmall*rightlarge + leftlarge*rightsmall;
        }
        return ans;
    }
};