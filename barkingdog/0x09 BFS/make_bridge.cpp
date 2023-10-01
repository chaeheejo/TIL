//
//  make_bridge.cpp
//  algorithm
//
//  Created by chaehee on 2023/10/01.
//

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

int N;
int answer = 2e9;
int board[100][100];

vector<pair<int, int>> edge;

int dxy[][2] = {
    0,1,
    1,0,
    -1,0,
    0,-1
};

void make_group(int i, int j, int val) {
    queue<pair<int, int>> q;
    q.push({ i,j });
    board[i][j] = val;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int flag = 0;

        for (int k = 0; k < 4; k++) {
            int nx = x + dxy[k][0];
            int ny = y + dxy[k][1];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if (board[nx][ny] == 1) {
                board[nx][ny] = val;
                q.push({ nx,ny });
            }
            else if (board[nx][ny] == 0) {
                flag = 1;
            }
        }

        if (flag) {
            edge.push_back({ x,y });
        }
    }
}

int find_other(int i, int j) {
    queue<pair<int, int>> q;
    q.push({ i,j });
    int visited[100][100] = { 0, };
    visited[i][j] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (visited[x][y] > answer) {
            return 1e9;
        }

        for (int k = 0; k < 4; k++) {
            int nx = x + dxy[k][0];
            int ny = y + dxy[k][1];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if (board[nx][ny] == 0) {
                if (visited[nx][ny] == 0) {
                    visited[nx][ny] = visited[x][y] + 1;
                    q.push({ nx,ny });
                }
            }
            else{
                if (board[nx][ny] != board[i][j]) {
                    return visited[x][y]-1;
                }
            }
        }
    }
    return 1e9;
}

int main() {

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    int cnt = 2;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                make_group(i, j, cnt);
                cnt++;
            }
        }
    }

    int answer = 1e9;

    for (int i = 0; i < edge.size(); i++) {
        answer = min(answer, find_other(edge[i].first, edge[i].second));
    }

    cout << answer;

    return 0;
}
