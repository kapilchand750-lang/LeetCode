class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorAll = 0;
        for(auto n : nums) xorAll ^= n;
        long long xr = xorAll;
        int mask = xr & (-xr);
        int b1 = 0, b2 = 0;
        for(auto n : nums){
            if((mask&n)!=0) b1 ^=n;
            else b2 ^= n;
        }
        return {b1, b2};
    }
};