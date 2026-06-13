class Solution {
  public:
    int romanToInt(string s) {
        unordered_map<char,int>map;
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;

        int n = s.size();       
        int i = n-2;

        int num = map[s[n-1]];
        while(i>=0){
           
            if(map[s[i]]>=map[s[i+1]])
                num += map[s[i]];
            else num -= map[s[i]];
            i--;
        }
        return num;
    }
};