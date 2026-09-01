class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(auto num : nums) total += num;

        if(total%2!=0) return false; // because an odd number cannot divide into two equal parts

        int half = total/2;

        int n = nums.size();

        vector<vector<bool>>dp(n+1, vector<bool>(half+1, false));

        // setting base condition
        for(int i = 0; i<=n; i++) dp[i][0] = true;

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=half; j++){
                dp[i][j] = dp[i-1][j];
                if(j>=nums[i-1]){
                    dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][half];
    }
};