#include <iostream> 
using namespace std;

//stack에는 지역 변수가 저장되고, heap에는 전역 변수가 저장되므로
//stack overflow가 나지 않으려면
//크기가 큰 배열은 전역 변수로 선언해 한번만 선언하는 것이 좋음
int board[1000001];
int order[1000001];
int dat[1000001]; //Direct Access Table

int main() {

	int T;
	cin >> T;

	int N;

	for (int t = 0; t < T; t++) {
		cin >> N;

		//board에는 학생들의 height가 들어간다.
		for (int i = 0; i < N; i++) {
			cin >> board[i];
		}

		//order에는 학생들의 height order가 들어간다.
		for (int i = 0; i < N; i++) {
			cin >> order[i];
		}

		//DAT의 index 값은 order, value 값은 height
		//입력된 height order의 순서대로 height 값이 저장되어 있음
		for (int i = 0; i < N; i++) {
			dat[order[i]] = board[i];
		}

		//DAT 배열을 height order 순으로 저장했으니
		//height 값이 차례대로 저장됐는지 순회하며 확인
		int flag = 0;
		for (int i = 1; i < N; i++) {
			if (dat[i] < dat[i + 1]) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
		}
	}


	return 0;
}