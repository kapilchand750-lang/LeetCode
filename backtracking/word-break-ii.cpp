class Solution {
    unordered_map<int, vector<string>>memo;

    vector<string> solve(string& s, vector<string>& wordDict, int idx){
        if(memo.count(idx))
            return memo[idx];

        vector<string>result;

        if(idx==s.size()){
            result.push_back("");
            return result;
        }

        for(auto word : wordDict){
            int len = word.size();
            if(len + idx <= s.size() && s.substr(idx, len)==word){
                vector<string> suffixes = solve(s, wordDict, len + idx);
                for(auto suffix : suffixes){
                    if(suffix.empty())
                        result.push_back(word);
                    else
                        result.push_back(word + " " + suffix);
                }
            }
        }
        return memo[idx] = result;
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
       return solve(s, wordDict, 0);
    }
};