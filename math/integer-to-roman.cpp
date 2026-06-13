class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>>sv;
        sv = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"},
        {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

        int i = 0;
        string roman;
        while(num>0){
            int div = sv[i].first;
            while(div<=num){
                roman +=sv[i].second;
                num -=div;
            }
            i++;
        }
        return roman;
    }
};