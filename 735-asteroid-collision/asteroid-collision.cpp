class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector <int> v;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]>0){
                v.push_back(asteroids[i]);
            }
            else{
                while(!v.empty() && v.back()>0 && v.back()<abs(asteroids[i])){
                    v.pop_back();
                }
                if(!v.empty() && v.back()==abs(asteroids[i])){
                    v.pop_back();
                }
                else if(v.empty() || v.back()<0){
                    v.push_back(asteroids[i]);
                }
            }
        }
        return v;
    }
};