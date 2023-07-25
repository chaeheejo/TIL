#include <iostream> 
using namespace std;

//stack���� ���� ������ ����ǰ�, heap���� ���� ������ ����ǹǷ�
//stack overflow�� ���� ��������
//ũ�Ⱑ ū �迭�� ���� ������ ������ �ѹ��� �����ϴ� ���� ����
int board[1000001];
int order[1000001];
int dat[1000001]; //Direct Access Table

int main() {

	int T;
	cin >> T;

	int N;

	for (int t = 0; t < T; t++) {
		cin >> N;

		//board���� �л����� height�� ����.
		for (int i = 0; i < N; i++) {
			cin >> board[i];
		}

		//order���� �л����� height order�� ����.
		for (int i = 0; i < N; i++) {
			cin >> order[i];
		}

		//DAT�� index ���� order, value ���� height
		//�Էµ� height order�� ������� height ���� ����Ǿ� ����
		for (int i = 0; i < N; i++) {
			dat[order[i]] = board[i];
		}

		//DAT �迭�� height order ������ ����������
		//height ���� ���ʴ�� ����ƴ��� ��ȸ�ϸ� Ȯ��
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