class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int>freq;
        for(auto a : nums)
            freq[a]++;
        vector<int>more;
        int n = nums.size()/3;
        for(auto p : freq){
            if(p.second>n)
                more.push_back(p.first);
        }
        return more;
    }
};