class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int>map;
        for(auto num : arr1)
            map[num]++;
        unordered_set<int>set(arr1.begin(), arr1.end());
        vector<int>ans;
        for(int i = 0; i<arr2.size(); i++){
            int num = arr2[i];
            int freq = map[num];
            set.erase(num);
            for(int j = 0; j<freq; j++){
                ans.push_back(num);
            }
        }
        
        vector<int>k(set.begin(), set.end());
        sort(k.begin(), k.end());
        for(int i = 0; i<k.size(); i++){
            int num = k[i];
            int freq = map[num];
            for(int j = 0; j<freq; j++){
                ans.push_back(num);
            }
        }
        return ans;
    }
};