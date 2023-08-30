//
//  fire!.cpp
//  algorithm
//
//  Created by chaehee on 2023/08/30.
//

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int N, M;
int answer = 1e9;
int ei, ej;
int board[1000][1000];
int fVisited[1000][1000];
int eVisited[1000][1000];

queue<pair<int, int>> fq;

int dxy[][2] = {
    0,1,
    0,-1,
    1,0,
    -1,0
};

void spread_fire() {
    while (!fq.empty()) {
        int x = fq.front().first;
        int y = fq.front().second;
        fq.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dxy[k][0];
            int ny = y + dxy[k][1];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (fVisited[nx][ny] == 0 && board[nx][ny] == 0) {
                fVisited[nx][ny] = fVisited[x][y] + 1;
                fq.push({ nx,ny });
            }
        }
    }
}

void escape() {
    eVisited[ei][ej] = 1;
    queue<pair<int, int>> q;
    q.push({ ei,ej });
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == 0 || x == N - 1 || y == 0 || y == M - 1) {
            answer = min(answer, eVisited[x][y]);
        }

        for (int k = 0; k < 4; k++) {
            int nx = x + dxy[k][0];
            int ny = y + dxy[k][1];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (eVisited[nx][ny] == 0 && board[nx][ny] == 0) {
                if (fVisited[nx][ny] > eVisited[x][y] + 1 || fVisited[nx][ny]==0) {
                    eVisited[nx][ny] = eVisited[x][y] + 1;
                    q.push({ nx,ny });
                }
            }
        }
    }
}

int main() {

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char temp;
            cin >> temp;

            if (temp == '#') {
                board[i][j] = -1;
            }
            else if (temp == 'J') {
                ei = i;
                ej = j;
            }
            else if (temp == 'F') {
                fVisited[i][j] = 1;
                fq.push({ i,j });
            }
        }
    }

    spread_fire();
    escape();

    if (answer == 1e9)
        cout << "IMPOSSIBLE";
    else
        cout << answer;

    return 0;
}
