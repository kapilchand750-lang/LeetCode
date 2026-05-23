class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int temp = 0;
        int pal = x;

        while (x > 0) {
            if (temp > (INT_MAX - x % 10) / 10) return false;
            temp = temp * 10 + x % 10;
            x = x / 10;
        }
        return temp == pal;
    }
};
