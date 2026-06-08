class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>dp(n+1, 0);
        dp[1] = 1;
        dp[0] = 1;
        for(int i = 2; i<=n; i++){
            dp[i] = i * dp[i-1];
        }

        string temp;
        vector<char>num;
        for(char c = '1'; c<='9'; c++)
            num.push_back(c);

        k--;
        for(int m = n-1; m>=0; m--){
            int idx = k/dp[m];
            temp.push_back(num[idx]);
            num.erase(num.begin()+idx);
            k = k%dp[m];
        }
        return temp;
    }
};