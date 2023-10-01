//
//  ball_icon.cpp
//  algorithm
//
//  Created by chaehee on 2023/10/01.
//

#include <iostream>
using namespace std;

int N, answer;
int board[50][9];
int path[9]; //path 안에는 0번부터 8번 타자를 순열로 만듦
int DAT[9]; //0번부터 8번 타자를 뽑았었는지 확인

void simulation() {
    int curIdx = 0;
    int score = 0; //현재 순열로 낼 수 있는 스코어
    for (int i = 0; i < N; i++) { //N 이닝 반복
        int map[4] = { 0, }; //1루, 2루, 3루 - 헷갈리니까 인덱스 그대로 사용
        int out = 0; //각 이닝마다 아웃이 3번되면 다음 이닝으로
        while (out < 3) {
            int curResult = board[i][path[curIdx]]; //현재 이닝에서 현재 타자가 낸 결과
            if (curResult == 0) { //아웃이면 횟수를 늘려주기만 함
                out++;
            }
            else if (curResult == 1) { //1루타면 3루에 사람이 있으면 점수를 내고, 2루->3루, 1루->2루, 1루에 타자
                score += map[3];
                map[3] = 0;

                map[3] = map[2];
                map[2] = map[1];

                map[1] = 1;
            }
            else if (curResult == 2) { //2루타면 3루, 2루에 사람이 있으면 점수를 내고, 1루->3루, 2루에 타자
                score += (map[2] + map[3]);
                map[3] = 0;
                map[2] = 0;
                
                map[3] = map[1];
                map[1] = 0;

                map[2] = 1;
            }
            else if (curResult == 3) { //3루타면 1,2,3루에 있는 사람마다 점수를 내고, 3루에 타자
                score += (map[1] + map[2] + map[3]);
                map[1] = 0;
                map[2] = 0;
                map[3] = 0;

                map[3] = 1;
            }
            else if (curResult == 4) {
                score += (map[1] + map[2] + map[3] + 1);
                map[1] = 0;
                map[2] = 0;
                map[3] = 0;
            }

            curIdx++; //현재 타자의 스코어를 기록했으니 다음 순번으로 옮겨줌
            if (curIdx >= 9) {
                curIdx = 0;
            }
        }
    }

    if (answer < score) {
        answer = score;
    }
}

void dfs(int curDepth) {
    if (curDepth == 9) {
        simulation();
        return;
    }
    if (curDepth == 3) {
        path[3] = 0; //1번 타자가 0번 타자.
        dfs(curDepth + 1);
    }
    else {
        for (int i = 1; i < 9; i++) {
            if (DAT[i] == 1)
                continue;
            DAT[i] = 1;
            path[curDepth] = i;
            dfs(curDepth + 1);
            DAT[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    DAT[0] = 1;

    dfs(0);

    cout << answer;

    return 0;
}
