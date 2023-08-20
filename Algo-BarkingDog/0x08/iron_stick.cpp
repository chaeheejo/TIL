//
//  iron_stick.cpp
//  algorithm
//
//  Created by chaehee on 2023/08/20.
//

#include <iostream>
#include <stack>
using namespace std;

int main() {

    string cmd;
    cin >> cmd;

    stack<char> st;
    int answer = 0;
    bool flag = false;
    for (int i = 0; i < cmd.size(); i++) {
        if (cmd[i] == '(') {
            st.push(cmd[i]);
            flag = true;
        }
        else {
            if (flag) {
                st.pop();
                answer += st.size();
            }
            else {
                answer++;
                st.pop();
            }
            flag = false;
        }
    }

    cout << answer;

    return 0;
}
