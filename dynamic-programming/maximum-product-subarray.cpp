class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 1;
        int suffix = 1;
        int maxProduct = nums[0];
        int n = nums.size();
        for(int i = 0, j = n-1; i<n; i++, j--){
            if(prefix == 0)
                prefix = 1;
            if(suffix == 0)
                suffix = 1;
            prefix *= nums[i];
            suffix *= nums[j];
            maxProduct = max(maxProduct, max(prefix, suffix)); 
        }
        return maxProduct;
    }
};