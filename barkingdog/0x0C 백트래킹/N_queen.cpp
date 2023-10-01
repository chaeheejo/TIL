//
//  N_queen.cpp
//  algorithm
//
//  Created by chaehee on 2023/10/01.
//

#include <iostream>
using namespace std;

int N, answer = 0;
int DAT[15];
int DAT_diagonal_left[50];
int DAT_diagonal_right[50];

void move_queen(int i) {
    if (i == N) {
        answer++;
        return;
    }

    for (int j = 0; j < N; j++) {
        if (DAT[j] == 1) {
            continue;
        }
        if (DAT_diagonal_left[i + j] == 1) {
            continue;
        }
        if (DAT_diagonal_right[i - j + N] == 1) {
            continue;
        }

        DAT[j] = 1;
        DAT_diagonal_left[i + j] = 1;
        DAT_diagonal_right[i - j + N] = 1;

        move_queen(i + 1);

        DAT[j] = 0;
        DAT_diagonal_left[i + j] = 0;
        DAT_diagonal_right[i - j + N] = 0;
    }
}

int main() {

    cin >> N;

    move_queen(0);

    cout << answer;

    return 0;
}
