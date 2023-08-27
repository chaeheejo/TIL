#include <iostream>
#include <cmath>
using namespace std;

//계산한 것을 기록해둔다는 의미
//overlapping subproblems - 한번에 풀지 못하고 작게 쪼개서 풀어야 한다.
//        dfs로 해결 가능?
//optimal substructure - 최적의 값을 구하면 그 값은 수정되지 않는다.
//        이전 선택이 이후에도 영향을 끼치지 않을 때

//TOP-DOWN 방식
//1. 기본적인 DFS 구조를 잡아줌
//2. 함수를 호출하는 것에 대해 정확한 의미를 부여
//    기존의 dfs : nx,ny로 가렴
//    현재 dfs : nx,ny에서의 최댓값을 알려주렴 - x,y에서의 최댓값을 구하려면 니가 필요해
//3. 맨 끝에서 값을 반환받음

//-> 값을 반환받으며 계산

//개구리 점프 문제
//각 단계에서 갈 수 있는 방향 중 가장 큰 수를 기록

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
        1,-1,
        1,0,
        1,1
};

//계산했던 것을 기록해 중복 계산을 피하는 목적
//dp[x][y] = x,y에서부터 최댓값을 기록
int dp[7][3];

int N = 7;
int M = 3;

int dfs(int x, int y) {
    //기저 조건 - 행을 전부 내려갔으면 끝냄
    if (x >= 6) {
        return board[x][y];
    }

    if (dp[x][y] != 0)
        return dp[x][y];

    //x,y 이전까지의 최대점수
    int maxScore = -1e9;
    for (int k = 0; k < 3; k++) {
        int nx = x + dxy[k][0];
        int ny = y + dxy[k][1];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;
        //벽을 만나면 무시
        if (board[nx][ny] == 0)
            continue;
        //nx,ny로 이동했을 때의 최대점수
        int nextScore = dfs(nx, ny);
        maxScore = max(maxScore, nextScore);
    }

    //x,y에서의 최대점수
    int nowScore = maxScore + board[x][y];
    dp[x][y] = nowScore;
    return nowScore;
}

int main() {

    dfs(1, 2);

    return 0;
}
