class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>set(nums1.begin(), nums1.end());
        vector<int>ans;
        for(int i = 0; i<nums2.size(); i++){
            int ele = nums2[i];
            if(set.find(ele)!=set.end()){
                ans.push_back(ele);
                set.erase(set.find(ele));
            }
        }
        return ans;
    }
};