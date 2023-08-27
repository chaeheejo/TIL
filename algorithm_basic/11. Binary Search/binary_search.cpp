#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
    int N;
    cin >> N;

    vector<int> board;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        board.push_back(temp);
    }

    sort(board.begin(), board.end());

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int temp;
        cin >> temp;

        int flag = 0;
        int left = 0;
        int right = board.size()-1;
        int mid = 0;
        while (true) {
            if (left > right) {
                break;
            }
            mid = (left + right) / 2;
            if (board[mid] > temp) {
                right = mid - 1;
            }
            else if (board[mid] < temp) {
                left = mid + 1;
            }
            else {
                flag = 1;
                break;
            }
        }

        if (flag) {
            cout << 'O';
        }
        else {
            cout << 'X';
        }
    }

    return 0;
}
