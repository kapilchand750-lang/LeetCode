class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subSet = 1<<n;
        vector<vector<int>>powerSet;
        for(int i = 0; i<subSet; i++){
            vector<int>sub;
            for(int j = 0; j<n; j++){
                if(i&(1<<j)) sub.push_back(nums[j]);
            }
            powerSet.push_back(sub);
        }
        return powerSet;
    }
};