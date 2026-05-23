class Solution {
public:
    int commonFactors(int a, int b) {
        int g = gcd(a,b);
        int cnt = 0;
        for(int i = 1; i*i<=g; i++){
            if(g%i==0) {
                cnt++;
                int k = g/i;
                if(k!=i) cnt++;
            }
        }
        return cnt;
    }
};