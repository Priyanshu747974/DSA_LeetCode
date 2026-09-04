class Solution {
public:
    int level(int label){
        int i =1;
        while(label > (1 << i) - 1){
            i++;
        }
        return i;
    }
    int mirror(int num,int level){
        int first = (1<<(level-1));
        int last = (1<<(level))-1;
        return first + last - num;
    }
    vector<int> pathInZigZagTree(int label) {
        vector<int> result;
        result.push_back(label);
        int levels = level(label);
        while(levels>1){
            // Even level = reversed
            if (levels % 2 == 0) {
                label = mirror(label, levels);
            }

            // Move to parent
            label /= 2;

            levels--;

            // Parent's level is reversed
            if (levels % 2 == 0) {
                label = mirror(label, levels);
            }

            result.push_back(label);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};