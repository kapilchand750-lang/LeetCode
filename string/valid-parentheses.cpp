#include<bits/stdc++.h>
class Solution {
public:
    bool isValid(string s) {
        stack <char> stk;
        unordered_map<char, char> tag = {
            {')','('},
            {']','['},
            {'}','{'}
        };
        for(char c : s){
            if( c=='(' || c=='{' || c=='[' ) stk.push(c);
            else {
                if(stk.empty() || stk.top()!=tag[c]) return 0;
                stk.pop();}
        }
        return stk.empty();
    }
};