#include <iostream>

using namespace std;

//�Լ� �������� ��� -> ���� ������ ���

void func(int n) {
	//2. ���� ����
	if (n == 9) {
		//3.3 ������ ���
		cout << n;
		return;
	}

	//3-1. �����ڽ��� ������ ���鼭 �۾�
	cout << n;

	//1. ��� �⺻ ���� - �ڱ� �ڽ� ȣ��
	func(n + 1);

	//3-2. �����ڽ��� ���� ���ƿ��鼭 �۾�
	cout << n;
}