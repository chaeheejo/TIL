//
//  hide_and_seek_four.cpp
//  algorithm
//
//  Created by chaehee on 2023/10/01.
//

#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;

#define MAX 200001

int N, K;
int board[MAX];
int pastStep[MAX];

void bfs() {
    queue<int> q;
    q.push(N);
    board[N] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == K) {
            cout << board[K] << '\n';

            vector<int> path;
            int idx = K;
            while (idx != N) {
                path.push_back(idx);
                idx = pastStep[idx];
            }

            cout << N << ' ';
            for (int i = path.size() - 1; i > -1; i--) {
                cout << path[i] << ' ';
            }
            return;
        }

        if (cur * 2 < MAX && board[cur * 2] == 1e9) {
            board[cur * 2] = board[cur] + 1;
            pastStep[cur * 2] = cur;
            q.push(cur * 2);
        }
        if (cur + 1 < MAX && board[cur + 1] == 1e9) {
            board[cur + 1] = board[cur] + 1;
            pastStep[cur + 1] = cur;
            q.push(cur + 1);
        }
        if (cur - 1 >= 0 && board[cur - 1] == 1e9) {
            board[cur - 1] = board[cur] + 1;
            pastStep[cur - 1] = cur;
            q.push(cur - 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 0; i < MAX; i++) {
        board[i] = 1e9;
        pastStep[i] = -1;
    }

    bfs();

    return 0;
}
