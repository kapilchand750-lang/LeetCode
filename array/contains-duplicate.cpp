class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int>map;
        for(auto e : nums) map[e]++;
        for(auto p : map){
            if(p.second>1) return true;
        }
        return false;
    }
    
};