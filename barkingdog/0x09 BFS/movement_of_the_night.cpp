//
//  movement_of_the_night.cpp
//  algorithm
//
//  Created by chaehee on 2023/08/30.
//

#include <iostream>
#include <queue>
using namespace std;

int N, si, sj, di, dj, answer;
int board[300][300];
int visited[300][300];

int dxy[][2] = {
    -2,1,
    -2,-1,
    -1,-2,
    1,-2,
    -1,2,
    1,2,
    2,1,
    2,-1
};

void bfs() {
    queue<pair<int, int>> q;
    q.push({ si,sj });
    visited[si][sj] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == di && y == dj) {
            answer = visited[x][y];
            break;
        }

        for (int k = 0; k < 8; k++) {
            int nx = x + dxy[k][0];
            int ny = y + dxy[k][1];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if (visited[nx][ny] > visited[x][y] + 1) {
                visited[nx][ny] = visited[x][y] + 1;
                q.push({ nx,ny });
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
        cin >> N;

        answer = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                board[i][j] = 0;
                visited[i][j] = 1e9;
            }
        }

        cin >> si >> sj >> di >> dj;

        bfs();

        cout << answer-1 << "\n";
    }

    return 0;
}
