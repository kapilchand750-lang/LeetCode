class Solution {
public:
    double rP(double x, long long n){
        if(n==0) return 1;
        if(n==1) return x;
        if(n%2==0) return rP(x*x, n/2);
        else return x*rP(x, n-1);
    }
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n==1) return x;
        if(n<0) return rP(1/x, -1*(long long)n);
        return rP(x, n);
    }
};