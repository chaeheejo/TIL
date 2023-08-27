#include <iostream>
#include <cmath>
using namespace std;

int board[7][3] = {
    1,0,0,
    1,2,2,
    0,3,0,
    3,-10,-5,
    15,-10,50,
    15,-10,10,
    0,6,4
};

int dxy[][2] = {
        -1,-1,
        -1,0,
        -1,1
};

int dp[7][3];
int N = 7;
int M = 3;

void bottom_up() {
    //시작점 설정
    dp[0][0] = board[0][0];

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            //내가 벽이면 무시
            if (board[i][j] == 0)
                continue;

            //i,j에 대한 시작점부터 해당 좌표까지 최대 점수
            int maxScore = -1e9;
            //바로 위 3개 좌표의 값을 확인해야 함
            for (int k = 0; k < 3; k++) {
                int pi = i + dxy[k][0];
                int pj = j + dxy[k][1];
                if (pi < 0 || pi >= N || pj < 0 || pj >= N)
                    continue;
                if (board[pi][pj] == 0)
                    continue;
                maxScore = max(maxScore, dp[pi][pj]);
            }

            dp[i][j] = maxScore + board[i][j];
        }
    }
}

int main() {

    bottom_up();

    return 0;
}
