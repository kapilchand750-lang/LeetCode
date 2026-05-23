class Solution {
public:
    string reverseWords(string s) {
        stack<char>st;
        string result;
        char c;
        for(int i = 0; i<s.size(); i++){
            if(s[i]==' '){
            while(!st.empty()){
                result.push_back(st.top());
                st.pop();
                }
            result.push_back(' ');
            }
            else st.push(s[i]);
        }
        while(!st.empty()){result.push_back(st.top());
        st.pop();}
        return result;
    }
};