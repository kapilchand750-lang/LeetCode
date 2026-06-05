class Solution {
    vector<vector<int>>all;
    void solve(vector<int>& nums, int k, int idx, int sum, vector<int>&temp){
        if(sum==k){
            all.push_back(temp);
            return;
        }
        for(int i = idx; i<nums.size(); i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            if(sum+nums[i]>k) break;
            temp.push_back(nums[i]);
            solve(nums, k, i+1, sum + nums[i], temp);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, 0, temp);
        return all;
    }
};