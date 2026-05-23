class Solution {
public:
    int getLeastFrequentDigit(int n) {
        n = abs(n);
        unordered_map<int,int> freq;
        set<int> digits;
        
        while (n > 0) {
            int rem = n % 10;
            freq[rem]++;
            digits.insert(rem);
            n /= 10;
        }

        int minFreq = INT_MAX;
        for (int d : digits) {
            if (freq[d] < minFreq) minFreq = freq[d];
        }

        int ans = 9;
        for (int d : digits) {
            if (freq[d] == minFreq) {
                ans = min(ans, d);
            }
        }
        return ans;
    }
};
