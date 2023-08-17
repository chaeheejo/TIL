//
//  queue.cpp
//  algorithm
//
//  Created by chaehee on 2023/08/17.
//

#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    queue<int> q;
    for (int i = 0; i < N; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int item;
            cin >> item;
            q.push(item);
        }
        else if (cmd == "front") {
            if (!q.empty()) {
                cout << q.front() << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }
        else if (cmd == "back") {
            if (!q.empty()) {
                cout << q.back() << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }
        else if (cmd == "size") {
            cout << q.size() << '\n';
        }
        else if (cmd == "empty") {
            cout << q.empty() << '\n';
        }
        else if (cmd == "pop") {
            if (!q.empty()) {
                cout << q.front() << '\n';
                q.pop();
            }
            else {
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}
