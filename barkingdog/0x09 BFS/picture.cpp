//
//  picture.cpp
//  algorithm
//
//  Created by chaehee on 2023/08/30.
//

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N, M, num, maxNum;
int board[500][500];
int visited[500][500];

int dxy[][2] = {
    0,1,
    0,-1,
    1,0,
    -1,0
};

void bfs(int i, int j) {
    num++;
    
    int cur = 0;

    visited[i][j] = 1;
    queue<pair<int, int>> q;
    q.push({ i,j });
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        cur++;

        for (int k = 0; k < 4; k++) {
            int nx = x + dxy[k][0];
            int ny = y + dxy[k][1];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;

            if (visited[nx][ny] == 0 && board[nx][ny] == 1) {
                visited[nx][ny] = 1;
                q.push({ nx,ny });
            }
        }
    }

    if (cur > maxNum) {
        maxNum = cur;
    }
}

int main() {

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] == 0 && board[i][j] == 1) {
                bfs(i, j);
            }
        }
    }

    cout << num << ' ' << maxNum;

    return 0;
}
