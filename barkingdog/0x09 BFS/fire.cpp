//
//  fire.cpp
//  algorithm
//
//  Created by chaehee on 2023/08/30.
//

#include <iostream>
#include <string>
#include <queue>
#include <utility>
using namespace std;

int N, M, answer;
int board[1000][1000];
int visited[1000][1000];
queue<pair<int, int>> fire;
int fireTime[1000][1000];
int si, sj;

int dxy[][2] = {
    0,1,
    0,-1,
    1,0,
    -1,0
};

void spreadFire() {
    while (!fire.empty()) {
        int x = fire.front().first;
        int y = fire.front().second;
        fire.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dxy[k][0];
            int ny = y + dxy[k][1];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (board[nx][ny] == 0 && fireTime[nx][ny] == 0) {
                fireTime[nx][ny] = fireTime[x][y] + 1;
                fire.push({ nx,ny });
            }
        }
    }
}

void move() {
    queue<pair<int, int>> q;
    q.push({ si,sj });
    visited[si][sj] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == 0 || x == N - 1 || y == 0 || y == M - 1) {
            answer = visited[x][y];
            break;
        }

        for (int k = 0; k < 4; k++) {
            int nx = x + dxy[k][0];
            int ny = y + dxy[k][1];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (board[nx][ny] == 0 && visited[nx][ny] == 0){
                if (fireTime[nx][ny] > visited[x][y] + 1 || fireTime[nx][ny]==0) {
                    visited[nx][ny] = visited[x][y] + 1;
                    q.push({ nx,ny });
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> M >> N;

        answer = 1e9;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                visited[i][j] = 0;
                board[i][j] = 0;
                fireTime[i][j] = 0;
            }
        }

        for (int i = 0; i < N; i++) {
            string temp;
            cin >> temp;

            for (int j = 0; j < temp.size(); j++) {
                if (temp[j] == '#') {
                    board[i][j] = -1;
                }
                else if (temp[j] == '*') {
                    fire.push({ i,j });
                    fireTime[i][j] = 1;
                }
                else if (temp[j] == '@') {
                    si = i;
                    sj = j;
                }
            }
        }

        spreadFire();
        move();

        if (answer == 1e9) {
            cout << "IMPOSSIBLE\n";
        }
        else {
            cout << answer << "\n";
        }
    }


    return 0;
}
