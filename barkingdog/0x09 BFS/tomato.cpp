//
//  tomato.cpp
//  algorithm
//
//  Created by chaehee on 2023/08/30.
//

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N, M;
int board[1000][1000];
int visited[1000][1000];
queue<pair<int, int>> q;

int dxy[][2] = {
    0,1,
    0,-1,
    1,0,
    -1,0
};

void bfs() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (board[x][y] == 1) {
            visited[x][y] = 1;
        }

        for (int k = 0; k < 4; k++) {
            int nx = x + dxy[k][0];
            int ny = y + dxy[k][1];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (board[nx][ny] == -1)
                continue;

            if (visited[nx][ny] == 0) {
                visited[nx][ny] = visited[x][y] + 1;
                q.push({ nx,ny });
            }
        }
    }
}

int main() {

    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 1) {
                q.push({ i,j });
            }
        }
    }

    bfs();

    int answer = 0, flag = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] > answer) {
                answer = visited[i][j];
            }
            if (board[i][j] == 0 && visited[i][j] == 0) {
                flag = 1;
            }
        }
    }

    answer--;
    if (flag)
        answer = -1;
    cout << answer;

    return 0;
}
