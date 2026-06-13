class Solution {
  public:
    int romanToInt(string s) {
        unordered_map<char,pair<int, int>>map;
        map['I'] = {1, 1};
        map['V'] = {5, 2};
        map['X'] = {10, 3};
        map['L'] = {50, 4};
        map['C'] = {100, 5};
        map['D'] = {500, 6};
        map['M'] = {1000, 7};
        
        int i = 1;
        int n = s.size();
        int num = map[s[0]].first;
        while(i<n){
            num += map[s[i]].first;
            if(map[s[i]].second>map[s[i-1]].second)
                num -= 2*map[s[i-1]].first;
            i++;
        }
        return num;
    }
};