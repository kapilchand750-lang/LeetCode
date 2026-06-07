class Solution {
    vector<vector<int>>all;

    void solve(vector<int>&nums, int mask, vector<int>&temp){
        if(nums.size()==temp.size()){
            all.push_back(temp);
            return;
        }

        for(int i = 0; i<nums.size(); i++){
            if(i>0 && nums[i]==nums[i-1] && ((mask&1<<(i-1))==0)) continue;
            if(mask&(1<<i)) continue;
            temp.push_back(nums[i]);
            solve(nums, mask|(1<<i), temp);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>temp;
        sort(nums.begin(), nums.end());
        solve(nums, 0, temp);
        return all;
    }
};