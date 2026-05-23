class Solution {
public:
    int fib(int n) {
        if(n<2) return n;
        int first = 0;
        int second = 1;
        int c;
        for(int i=2; i<=n; i++){
            c=first+second;
            first=second;
            second=c;
        }
        return c;
    }
};