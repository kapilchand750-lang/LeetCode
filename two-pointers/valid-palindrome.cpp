class Solution {
public:
    bool isPalindrome(string s) {
        string k;

        for (char c : s) {
            if (isalnum(c))
                k.push_back(tolower(c));
        }

        for (int i = 0; i < k.size() / 2; i++) {
            if (k[i] != k[k.size() - 1 - i])
                return false;
        }

        return true;
    }
};
