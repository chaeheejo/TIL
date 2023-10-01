//
//  numbering_group.cpp
//  algorithm
//
//  Created by chaehee on 2023/10/01.
//

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
int board[25][25];
vector<int> answer;

int dxy[][2] = {
    0,1,
    0,-1,
    1,0,
    -1,0
};

int count_group(int i, int j) {
    queue<pair<int, int>> q;
    q.push({ i,j });
    board[i][j] = 0;
    int rtn = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dxy[k][0];
            int ny = y + dxy[k][1];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if (board[nx][ny] == 1) {
                board[nx][ny] = 0;
                q.push({ nx,ny });
                rtn++;
            }
        }
    }
    
    return rtn;
}

int main() {

    cin >> N;

    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;

        for (int j = 0; j < temp.size(); j++) {
            board[i][j] = temp[j]-'0';
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                answer.push_back(count_group(i, j));
            }
        }
    }

    cout << answer.size() << "\n";

    sort(answer.begin(), answer.end());

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << '\n';
    }

    return 0;
}
