class Solution {

    bool solve(string s, vector<string>& wordDict, int idx, vector<int>& dp){
        if(idx == s.size())
            return true;

        if(dp[idx]!=-1)
            return dp[idx];

        for(auto word : wordDict){
            int n = word.size();
            if(idx + n <=s.size() && s.substr(idx, n)==word){
                if(solve(s, wordDict, idx + n, dp))
                    return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int>dp(n+1, -1);
        return solve(s, wordDict, 0, dp);
    }
};