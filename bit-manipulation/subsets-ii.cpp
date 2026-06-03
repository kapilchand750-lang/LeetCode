class Solution {
private:
    vector<vector<int>>all;

    void solve(vector<int>& nums, int idx, int n, vector<int>&temp){
        all.push_back(temp);
        for(int i = idx; i<n; i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(nums, i+1, n, temp);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<int>temp;
       int n = nums.size();
       sort(nums.begin(), nums.end());
       solve(nums, 0, n, temp);
       return all; 
    }
};