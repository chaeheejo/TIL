//
//  bracket.cpp
//  algorithm
//
//  Created by chaehee on 2023/08/20.
//

#include <iostream>
#include <stack>
using namespace std;

int main() {

    int N;
    cin >> N;

    for (int n = 0; n < N; n++) {
        string cur;
        cin >> cur;

        bool flag = true;
        stack<char> st;
        for (int i = 0; i < cur.size(); i++) {
            if (cur[i] == '(') {
                st.push(cur[i]);
            }
            else if (cur[i] == ')') {
                if (st.empty()) {
                    flag = false;
                    break;
                }
                else if (st.top() != ')') {
                    st.pop();
                }
            }
        }
        if (!flag || !st.empty()) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";

    }

    return 0;
}
