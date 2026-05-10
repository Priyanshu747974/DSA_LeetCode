class StockSpanner {
public:
    vector<int> list;
    StockSpanner() {

    }
    
    int next(int price) {
       list.push_back(price);
       int cnt=1; 
       for(int i=list.size()-2;i>=0;i--){
        if(list[i]<=price){
            cnt++;
        }
        else{
            break;
        }
       }
       return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */