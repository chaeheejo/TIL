//
//  organic_cabbage.cpp
//  algorithm
//
//  Created by chaehee on 2023/08/30.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, K;
int board[50][50];
int visited[50][50];

int dxy[][2] = {
    0,1,
    1,0,
    0,-1,
    -1,0
};

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({ i,j });
    visited[i][j] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dxy[k][0];
            int ny = y + dxy[k][1];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;

            if (board[nx][ny] == 1 && visited[nx][ny] == 0) {
                visited[nx][ny] = 1;
                q.push({ nx,ny });
            }
        }
    }
}

int main() {

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> M >> N >> K;

        //init
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                board[i][j] = 0;
                visited[i][j] = 0;
            }
        }

        for (int k = 0; k < K; k++) {
            int i, j;
            cin >> j >> i;
            board[i][j] = 1;
        }
        
        int answer = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == 1 && visited[i][j] == 0) {
                    bfs(i, j);
                    answer++;
                }
            }
        }

        cout << answer << "\n";
    }

    return 0;
}
