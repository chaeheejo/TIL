//
//  AC.cpp
//  algorithm
//
//  Created by chaehee on 2023/08/17.
//

#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 0;
    cin >> T;

    for (int t = 0; t < T; t++) {
        string cmd;
        cin >> cmd;

        int N;
        cin >> N;

        string str;
        cin >> str;
        if (str.size() == 2) {
            if (cmd.find("D") != string::npos) {
                cout << "error\n";
                continue;
            }
            else {
                cout << "[]\n";
                continue;
            }
        }
        str.erase(str.begin());
        str.erase(str.end()-1);
    
        deque<int> dq;
        int start = 0, next = 0;
        while ((next = str.find(",", start)) != string::npos) {
            dq.push_back(stoi(str.substr(start, next - start)));
            start = next + 1;
        }
        dq.push_back(stoi(str.substr(start)));

        int flag = 0;
        int reverseCnt = 0;
        for (int i = 0; i < cmd.size(); i++) {
            if (cmd[i] == 'R') {
                reverseCnt++;
            }
            else {
                if (reverseCnt % 2 == 0) {
                    if (!dq.empty()) {
                        dq.pop_front();
                    }
                    else {
                        cout << "error\n";
                        flag = 1;
                        break;
                    }
                }
                else {
                    if (!dq.empty()) {
                        dq.pop_back();
                    }
                    else {
                        cout << "error\n";
                        flag = 1;
                        break;
                    }
                }
            }
        }

        if (flag) {
            continue;
        }

        if (reverseCnt % 2 == 0) {
            cout << "[";
            auto it = dq.begin();
            if (it == dq.end()) {
                cout << "]\n";
                continue;
            }
            while (it != dq.end()) {
                if (it == dq.end() - 1) {
                    cout << dq.front() << "]\n";
                }
                else {
                    cout << dq.front() << ",";
                }
                dq.pop_front();
                it = dq.begin();
            }
        }
        else {
            cout << "[";
            auto it = dq.end();
            if (it == dq.begin()) {
                cout << "]\n";
                continue;
            }
            while (it != dq.begin()) {
                if (it == dq.begin() + 1) {
                    cout << dq.back() << "]\n";
                }
                else {
                    cout << dq.back() << ",";
                }
                dq.pop_back();
                it = dq.end();
            }
        }
    }

    return 0;
}
