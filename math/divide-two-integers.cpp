class Solution {
public:
    int divide(int dividend, int divisor) {

        // Only overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool sign = (dividend < 0) ^ (divisor < 0);

        long long x = llabs((long long)dividend);
        long long y = llabs((long long)divisor);

        long long ans = 0;

        while (x >= y) {
            int cnt = 0;
            while (x >= (y << (cnt + 1)))
                cnt++;

            ans += (1LL << cnt);
            x -= (y << cnt);
        }

        return sign ? -ans : ans;
    }
};
