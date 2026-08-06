class Solution {
public:
    int product(int n){
        int prod = 1;
        while(n!=0){
            prod = prod*(n%10);
            n = n/10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
      int i = 1;
      int prod = 1;
      int ans;

      for(int i=n;i<n+10;i++){
        if(product(i)%t==0){
            ans = i;
            break;
        }
        else{
            continue;
        }
      }
      /*
      while(prod%t!=0){
        prod = product(n);
        if(prod%t==0){
            ans = n;
        }
        n = n+i;
        i++;
      }
      */
      return ans;
    }
};