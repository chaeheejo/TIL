#include <iostream>
using namespace std;

int N, M;
int DAT[6+1];
int path[10];

int dice[6] = { 1,2,3,4,5,6 };

void combination(int depth) {
    if (depth == N) {
        for (int i = 0; i < N; i++) {
            cout << path[i] <<' ';
        }
        cout << endl;

        return;
    }

    for (int i = 0; i < 6; i++) {
        int flag = 0;

        if (depth > 0) {
            if (dice[i] < path[depth-1]) {
                continue;
            }
        }

        path[depth] = dice[i];

        combination(depth + 1);

        path[depth] = 0;
    }
}

void permutation(int depth) {
    if (depth == N) {
        for (int i = 0; i < N; i++) {
            cout << path[i] << ' ';
        }
        cout << endl;

        return;
    }

    for (int i = 0; i < 6; i++) {
        if (DAT[dice[i]] == 1) {
            continue;
        }

        path[depth] = dice[i];
        DAT[dice[i]] = 1;

        permutation(depth + 1);

        path[depth] = 0;
        DAT[dice[i]] = 0;
    }
}

void duplicate_permutation(int depth) {
    if (depth == N) {
        for (int i = 0; i < N; i++) {
            cout << path[i] << ' ';
        }
        cout << endl;

        return;
    }

    for (int i = 0; i < 6; i++) {

        path[depth] = dice[i];

        duplicate_permutation(depth + 1);

        path[depth] = 0;
    }
}

int main() {

    cin >> N >> M;

    if (M == 1) {
        duplicate_permutation(0);
    }
    else if (M == 2) {
        combination(0);
    }
    else {
        permutation(0);
    }

    return 0;
}