class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = nums[0], maxsum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            pre = max(nums[i], pre + nums[i]);
            maxsum = max(maxsum, pre);
        }
        return maxsum;
    }
};
