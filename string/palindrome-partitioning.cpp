class Solution {
    vector<vector<string>>all;

    bool isSafe(string& s, int i, int j){
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }

    void solve(string& s, vector<string>&temp, int idx){
        if(idx == s.size()){
            all.push_back(temp);
            return;
        }

        for(int i = idx; i<s.size(); i++){
            if(isSafe(s, idx, i)){
                temp.push_back(s.substr(idx, i - idx + 1));
                solve(s, temp, i+1);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        solve(s, temp, 0);
        return all;
    }
};