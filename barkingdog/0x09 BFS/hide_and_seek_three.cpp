//
//  hide_and_seek_three.cpp
//  algorithm
//
//  Created by chaehee on 2023/10/01.
//

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

#define MAX 500001

int N, K;
int board[MAX];

int bfs() {
    queue<int> q;
    q.push(N);
    board[N] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (x == K) {
            return board[K] - 1;
        }

        if (2 * x < MAX && board[2 * x] > board[x]) {
            board[2 * x] = board[x];
            q.push(2 * x);
        }
        if (x - 1 >= 0 && board[x - 1] > board[x] + 1) {
            board[x - 1] = board[x] + 1;
            q.push(x - 1);
        }
        if (x + 1 < MAX && board[x + 1] > board[x] + 1) {
            board[x + 1] = board[x] + 1;
            q.push(x + 1);
        }
    }
    return 1e9;
}

int main() {

    cin >> N >> K;

    for (int i = 0; i < MAX; i++) {
        board[i] = 10000000;
    }

    int answer = min(MAX, bfs());

    cout << answer;

    return 0;
}
