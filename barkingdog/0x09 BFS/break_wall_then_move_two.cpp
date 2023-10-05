//
//  break_wall_then_move_two.cpp
//  algorithm
//
//  Created by chaehee on 10/5/23.
//

#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int N, M, K;
int board[1000][1000];
int visited[1000][1000][11];

int dxy[][2] = {
    0,1,
    1,0,
    -1,0,
    0,-1
};

void bfs() {
    queue<tuple<int, int, int>> q;
    q.push({ 0,0,0 });
    visited[0][0][0] = 1;
    while (!q.empty()) {
        int i = get<0>(q.front());
        int j = get<1>(q.front());
        int wall = get<2>(q.front());
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = i + dxy[k][0];
            int ny = j + dxy[k][1];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;

            if (board[nx][ny] == 0) {
                if (visited[nx][ny][wall] > 0) //방문한 적 있으면
                    continue;
                visited[nx][ny][wall] = visited[i][j][wall] + 1;
                q.push({ nx,ny,wall });
            }
            else { //벽을 뚫어야 하면
                if (wall+1 > K)
                    continue;
                if (visited[nx][ny][wall + 1] > 0) //방문한 적 있는지 확인
                    continue;
                visited[nx][ny][wall + 1] = visited[i][j][wall] + 1;
                q.push({ nx,ny,wall+1 });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;

        for (int j = 0; j < temp.size(); j++) {
            if (temp[j] == '1') board[i][j] = 1;
        }
    }

    bfs();

    int answer = 2e9;
    for (int k = 0; k <= K; k++) {
        if (visited[N - 1][M - 1][k] == 0) continue;
        answer = min(answer, visited[N - 1][M - 1][k]);
    }

    if (answer == 2e9)
        cout << -1;
    else
        cout << answer;

    return 0;
}
