//
//  balanced_world.cpp
//  algorithm
//
//  Created by chaehee on 2023/08/17.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    while (1) {
        getline(cin, str);
        if (str == ".") {
            break;
        }

        stack<char> st;
        int idx = 0, open = 0, close = 0;
        while (idx < str.size()-1) {
            if (str[idx] == '[' || str[idx]=='(') {
                st.push(str[idx]);
                open = 1;
            }
            else if (str[idx] == ']') {

            }
            else if (str[idx] == ')') {

            }
            else if (open && str[idx] == ']' || str[idx] == ')') {
                while(!st.empty() && st.top())
                if (('A' <= st.top() && 'Z' >= st.top()) || ('a' <= st.top() && 'z' >= st.top())) {
                    st.pop();
                }
            }
            if (open) {
                st.push(str[idx]);
            }
            idx++;
        }
    }

    return 0;
}
