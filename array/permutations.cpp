class Solution {
    vector<vector<int>>all;
    void solve(vector<int>&nums, vector<int>&temp, int mask){
        if(nums.size()==temp.size()){
            all.push_back(temp);
            return;
        }

        for(int i = 0; i<nums.size(); i++){
            if((mask&(1<<i))==0){
                temp.push_back(nums[i]);
                solve(nums, temp, mask|(1<<i));
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        solve(nums, temp, 0);
        return all;
    }
};