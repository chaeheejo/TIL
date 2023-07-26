#include <iostream>
#include <vector>
using namespace std;

int N, answer;
int DAT[10];
int DAT_j[10];

void move_castle(int i) {
    if (i == N) {
        answer++;
        return;
    }

    for (int j = 0; j < N; j++) {
        if (DAT[j] == 1) {
            continue;
        }

        DAT[j] = 1;
        move_castle(i + 1);
        DAT[j] = 0;
    }
}

int main() {

    cin >> N ;

    move_castle(0);

    cout << answer;

    return 0;
}