class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        string r, word;
        stringstream ss(s);
        while(ss >> word){
            reverse(word.begin(), word.end());
            r += word + " ";
        }
        r.pop_back();
        return r;
    }
};