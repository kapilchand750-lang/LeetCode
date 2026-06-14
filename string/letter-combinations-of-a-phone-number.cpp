class Solution {
    vector<string>ans;

    void solve(string& digits, int idx, string& temp, vector<string>&map){

        if(digits.empty()) return;

        if(idx==digits.size()){
            ans.push_back(temp);
            return;
        }

        string str = map[digits[idx]-'0'];

        if(str.empty())
            solve(digits, idx + 1, temp, map);
        
        for(int i = 0; i<str.size(); i++){
            temp.push_back(str[i]);
            solve(digits, idx + 1, temp, map);
            temp.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        string temp;
        vector<string>map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, 0, temp, map);
        return ans;
    }
};