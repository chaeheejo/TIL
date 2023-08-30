//
//  hide_and_seek.cpp
//  algorithm
//
//  Created by chaehee on 2023/08/30.
//

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int board[100001];

int main() {

    int N, K;
    cin >> N >> K;

    int answer = 0;

    for (int i = 0; i < 100001; i++) {
        board[i] = 1e9;
    }

    queue<pair<int,int>> q;
    q.push({N, 0});
    while (!q.empty()) {
        int x = q.front().first;
        int step = q.front().second;
        q.pop();

        if (x == K) {
            answer = step;
            break;
        }

        if (2*x<100001 && board[2 * x] > step + 1) {
            board[2 * x] = step + 1;
            q.push({ 2 * x,step + 1 });
        }
        if (x-1>-1 && board[x - 1] > step + 1) {
            board[x - 1] = step + 1;
            q.push({ x - 1, step + 1 });
        }
        if (x+1<100001 && board[x + 1] > step + 1) {
            board[x + 1] = step + 1;
            q.push({ x + 1, step + 1 });
        }

    }

    cout << answer;

    return 0;
}
