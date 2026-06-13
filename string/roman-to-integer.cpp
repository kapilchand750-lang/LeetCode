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

        int n = s.size();       
        int i = n-2;

        int num = map[s[n-1]].first;
        while(i>=0){
           
            if(map[s[i]].second>=map[s[i+1]].second)
                num += map[s[i]].first;
            else num -= map[s[i]].first;
            i--;
        }
        return num;
    }
};