//
//  monkey_wants_to_be_horse.cpp
//  algorithm
//
//  Created by chaehee on 2023/10/01.
//

#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

#define MAX 100000000

int K, N, M;
int board[200][200];
int visited[200][200][31];

int dxy[][2] = {
    0,1,
    1,0,
    0,-1,
    -1,0
};
int hdxy[][2] = {
    -2,1,
    -2,-1,
    -1,2,
    -1,-2,
    1,2,
    1,-2,
    2,1,
    2,-1
};

int bfs() {
    queue<tuple<int, int, int>> q;
    q.push({ 0,0,0 });

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int m = 0; m < 31; m++) {
                visited[i][j][m] = MAX;
            }
        }
    }
    visited[0][0][0] = 0;

    while (!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int h = get<2>(q.front());
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dxy[k][0];
            int ny = y + dxy[k][1];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (board[nx][ny] == 1)
                continue;

            if (visited[nx][ny][h] == MAX) {
                visited[nx][ny][h] = visited[x][y][h] + 1;
                q.push({ nx,ny,h });
            }
        }

        if (h >= K) continue;

        for (int k = 0; k < 8; k++) {
            int nx = x + hdxy[k][0];
            int ny = y + hdxy[k][1];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (board[nx][ny] == 1)
                continue;

            if (visited[nx][ny][h + 1] == MAX) {
                visited[nx][ny][h + 1] = visited[x][y][h] + 1;
                q.push({ nx,ny,h + 1 });
            }
        }
    }

    int rtn = MAX;
    for (int i = 0; i <= K; i++) {
        rtn = min(rtn, visited[N - 1][M - 1][i]);
    }
    return rtn;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    int answer = bfs();

    if (answer == MAX) {
        cout << -1;
    }
    else {
        cout << answer;
    }

    return 0;
}
