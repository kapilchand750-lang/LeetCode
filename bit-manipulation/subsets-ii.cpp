class Solution {
private:
    set<vector<int>>all;

    void solve(vector<int>&nums, int n, int i, vector<int>&temp){
        if(i==n){
            all.insert(temp);
            return;
        }

        temp.push_back(nums[i]);
        solve(nums, n, i+1, temp);
        temp.pop_back();
        solve(nums, n, i+1, temp);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp;
        sort(nums.begin(), nums.end());
        solve(nums, n, 0, temp);
        vector<vector<int>>ans(all.begin(), all.end());
        return ans;
    }
};