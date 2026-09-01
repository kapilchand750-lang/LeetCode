class Solution {
    unordered_map<string, int>map;
    vector<vector<string>>rs;
private:
    void dfs(string beginWord, string endWord, vector<string>& seq){
        if(endWord == beginWord){
            reverse(seq.begin(), seq.end());
            rs.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        int level = map[endWord];
        int n = endWord.size();
        for(int i = 0; i<n; i++){
            char original = endWord[i];
            for(char ch = 'a'; ch<='z'; ch++){
                if(ch == original) continue;
                endWord[i] = ch;
                if(map.find(endWord)!=map.end() && map[endWord] + 1 == level){
                    seq.push_back(endWord);
                    dfs(beginWord, endWord, seq);
                    seq.pop_back();
                }
            }
            endWord[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>q;

        unordered_set<string>set(wordList.begin(), wordList.end());

        q.push(beginWord);
        set.erase(beginWord);
        map[beginWord] = 1;

        while(!q.empty()){
            string s = q.front();
            q.pop();
            int level = map[s];

            if(s==endWord) break;
            int n = s.size();
            for(int i = 0; i<n; i++){
                char original = s[i];
                for(auto ch = 'a'; ch<='z'; ch++){
                    if(ch == original) continue;
                    s[i] = ch;
                    if(set.find(s)!=set.end()){
                        q.push(s);
                        map[s] = level+1;
                        set.erase(s);
                    }
                }
                s[i] = original;
            }
        }

        if(map.find(endWord)!=map.end()){
            vector<string>seq;
            seq.push_back(endWord);
            dfs(beginWord, endWord, seq);
        }
        return rs;
    }
};