//
//  count_area.cpp
//  algorithm
//
//  Created by chaehee on 2023/10/01.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int N, M, K;
int board[100][100];
vector<int> answer;

int dxy[][2] = {
    0,1,
    1,0,
    0,-1,
    -1,0
};

void make_square(int si, int sj, int di, int dj) {
    for (int i = di; i < si; i++) {
        for (int j = sj; j < dj; j++) {
            board[i][j] = 1;
        }
    }
}

int count_group(int i, int j) {
    queue<pair<int, int>> q;
    q.push({ i,j });
    board[i][j] = 1;
    int rtn = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dxy[k][0];
            int ny = y + dxy[k][1];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (board[nx][ny] == 0) {
                board[nx][ny] = 1;
                rtn++;
                q.push({ nx,ny });
            }
        }
    }
    return rtn;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    for (int i = 0; i < K; i++) {
        int si, sj, di, dj;
        cin >> sj >> si >> dj >> di;
        si = N - si;
        di = N - di;
        make_square(si, sj, di, dj);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0) {
                answer.push_back(count_group(i,j));
            }
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << '\n';

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }

    return 0;
}
