class Solution {
    vector<vector<int>>all;

    void solve(vector<int>& candidates, int n, int k, int i, int sum, vector<int>&temp){
        if(sum==k){
            all.push_back(temp);
            return;
        }
        if(sum>k || i>=n) return;
        temp.push_back(candidates[i]);
        solve(candidates, n, k, i, sum + candidates[i], temp);
        temp.pop_back();
        solve(candidates, n, k, i+1, sum, temp);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        int n = candidates.size();
        solve(candidates, n, target, 0, 0, temp);
        return all;
    }
};