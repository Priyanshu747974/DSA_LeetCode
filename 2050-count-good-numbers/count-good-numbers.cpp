class Solution {
public:
    long long mod=1e9+7;
    long long be(long long x,long long n){
        long long N=n;
        if(N<0){
            x=1/x;
            N=-N;
        }
        return power(x,N);
    }
    long long power(long long x,long long n){
        if(n==0){
            return 1;
        }
        long long half = power(x,n/2);
        if(n%2==0){
            return (half*half)%mod;
        }
        else{
            return ((x*half)%mod*half)%mod;
        }
    }
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long odd =n/2;
        return  ((be(4,odd)%mod)*(be(5,even)%mod))%mod;
    }
};