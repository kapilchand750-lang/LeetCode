class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>>map;
        int n = s.size();
        for(int i = 0; i<n; i++){
            char c = s[i];
            if(map.find(c)!=map.end())
                map[c].first += 1;
            else map[c] = {1, i};
        }

        int minPos = INT_MAX;
        for(auto p : map){
            int freq = p.second.first;
            if(freq==1){
                minPos = min(minPos, p.second.second);
            }
        }
        return (minPos!=INT_MAX) ? minPos : -1;
    }
};