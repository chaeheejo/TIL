//
//  N_and_M_eight.cpp
//  algorithm
//
//  Created by chaehee on 2023/10/01.
//

#include <iostream>
using namespace std;

int N, M;
int board[8];
int path[8]; //board의 index를 저장

void dfs(int curDepth, int idx) {
    if (curDepth == M) {
        for (int i = 0; i < M; i++) {
            cout << board[path[i]]<<' ';
        }
        cout << "\n";
        return;
    }
    for (int i = idx; i < N; i++) {
        path[curDepth] = i;
        dfs(curDepth + 1, i);
    }
}

int main() {

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (board[i] > board[j]) {
                int temp = board[i];
                board[i] = board[j];
                board[j] = temp;
            }
        }
    }

    dfs(0,0);

    return 0;
}
