#include <iostream>
using namespace std;

int N;
long long M;
int board[10001];

int main() {
    
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    int answer = 0;
    int sum = board[0];
    int left = 0, right = 0;
    while (left <= right && left<N && right<N) {
        if (sum < M) { //사이에 있는 값이 M보다 작은 경우
            right++; //범위를 늘려줌
            sum += board[right];
        }
        else if (sum > M) { //사이에 있는 값이 M보다 큰 경우
            sum -= board[left];
            left++; //범위를 줄여줌
        }
        else { //M인 경우
            answer++;
            if (left < right) {
                sum -= board[left];
                left++;
            }
            else {
                right++;
                left++;
                sum = board[right];
            }

        }
    }

    cout << answer;

    return 0;
}
