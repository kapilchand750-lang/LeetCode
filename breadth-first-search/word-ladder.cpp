class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>>q;
        
        unordered_set<string>set(wordList.begin(), wordList.end());
        
        if(set.find(endWord)==set.end()) return 0;

        q.push({beginWord, 1});
        set.erase(beginWord);

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            string word = it.first;
            int level = it.second;
            if(word == endWord) return level;

            for(int i = 0; i<word.size(); i++){
                char original = word[i];
                for(char ch = 'a'; ch<='z'; ch++){
                    
                    if(ch==original) continue;
    
                    word[i] = ch;
                    if(set.find(word)!=set.end()){
                        q.push({word, level+1});
                    set.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};