class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int count = 0;
        for(auto c : nums){
            count += c;
            count *= c;
            maxi = max(maxi, count);
        }
        return maxi;
    }
};