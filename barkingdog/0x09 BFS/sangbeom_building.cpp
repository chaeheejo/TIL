//
//  sangbeom_building.cpp
//  algorithm
//
//  Created by chaehee on 2023/08/30.
//

#include <iostream>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

int L, N, M, answer;
int sl, si, sj, dl, di, dj;
int board[30][30][30];
int visited[30][30][30];

int dxy[][3] = {
    0,1,0,
    0,-1,0,
    0,0,1,
    0,0,-1,
    1,0,0,
    -1,0,0,
};

void bfs() {
    queue<tuple<int, int, int>> q;
    q.push({ sl,si,sj });
    visited[sl][si][sj] = 1;
    while (!q.empty()) {
        int l = get<0>(q.front());
        int x = get<1>(q.front());
        int y = get<2>(q.front());
        q.pop();

        if (l == dl && x == di && y == dj) {
            answer = visited[l][x][y];
            break;
        }

        for (int k = 0; k < 6; k++) {
            int nl = l + dxy[k][0];
            int nx = x + dxy[k][1];
            int ny = y + dxy[k][2];
            if (nl < 0 || nl >= L || nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (visited[nl][nx][ny] == 0 && board[nl][nx][ny] == 0) {
                visited[nl][nx][ny] = visited[l][x][y] + 1;
                q.push({ nl,nx,ny });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        answer = -1;
        cin >> L >> N >> M;

        if (L == 0 && N == 0 && M == 0) {
            break;
        }

        for (int l = 0; l < 30; l++) {
            for (int i = 0; i < 30; i++) {
                for (int j = 0; j < 30; j++) {
                    visited[l][i][j] = 0;
                    board[l][i][j] = 0;
                }
            }
        }

        for (int l = 0; l < L; l++) {
            for (int i = 0; i < N; i++) {
                string temp;
                cin >> temp;

                for (int j = 0; j < temp.size(); j++) {
                    if (temp[j] == 'S') {
                        si = i;
                        sj = j;
                        sl = l;
                    }
                    else if (temp[j] == 'E') {
                        di = i;
                        dj = j;
                        dl = l;
                    }
                    else if (temp[j] == '#') {
                        board[l][i][j] = -1;
                    }
                }
            }
        }

        bfs();

        if (answer == -1) {
            cout << "Trapped!\n";
        }
        else {
            cout << "Escaped in " << answer-1 << " minute(s).\n";
        }
    }


    return 0;
}
