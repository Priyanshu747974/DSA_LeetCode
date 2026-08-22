class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int total = 0;
        for(int i =0;i<possible.size();i++){
            if(possible[i]==0){
                possible[i]=-1;
            }
            total = total+possible[i];
        }
        int alice = 0;
        int bob = 0;
        int i = 0;
        while(i<possible.size()-1){
            alice = alice + possible[i];
            bob = total - alice;
            if(alice>bob){
              return i+1;  
            }
            i++;
        }
       return -1;
    }
};