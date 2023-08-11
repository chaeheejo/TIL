#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring> //char[] ���
#include <string> //string

using namespace std;

int main() {

	//strcmp, strlen, strcpy, memset

	char str1[100] = "ABC";
	char str2[100] = "DEF";

	//strcmp - ���ڿ� ��
	//str1�� ���������� ���� ��� : return ����
	//�� ���ڰ� ���� ��� : return 0
	//str2�� ���������� ���� ��� : return ���
	//���������� str1, str2�� ���ڿ� ������ŭ �ݺ�
	cout << strcmp(str1, str2) << "\n";

	//strlen - ���ڿ��� ����
	//���������� NULL(='\0' =0(ascii code) =false)�� ���� ������
	//���ڿ� ������ŭ �ݺ�
	cout << strlen(str1) << "\n";

	//strcpy - ���ڿ��� ����
	char str3[100];
	strcpy(str3, str2);
	cout << str3 << "\n";

	//memset - data�� ��°�� ����
	//�ʱ�ȭ�� �� ���� ��
	//���� - ����Ʈ ������ ���� �ֱ⿡ 4����Ʈ�� int������ ���ϴ� ���� �� ��
	//memset�� int �迭���� 0�̳� -1�� �ʱ�ȭ�� �� ���
	//���������� �迭�� ���̸�ŭ �ݺ�
	int arr[100];
	memset(arr, 0, sizeof(arr));
	memset(arr, -1, sizeof(arr));

	for (int i = 0; i < 100; i++) {
		arr[i] = -1;
	} //�� �ٸ��� ����
	//algorithm ���̺귯���� fill �Լ��� ���ϴ� ���� �־���(int��)
	

	//string�� char �迭�̶� �ٸ�
	string str = "1234";
	char str5[100] = "123";
	//string�� NULL ���� �����Ͱ� ����, char �迭�� NULL�� �������� ����
	//NULL�� ���� ���� ���� : string�� �������� ũ�⸦ size�� ������ �� ����

	//������ �� �ε�ȣ��
	//���������� ���ڿ� ���̸�ŭ �ݺ�
	string a = "ABC";
	string b = "ABB";
	if (a > b) {
		cout << "a�� ���������� ����\n";
	}

	//���ڿ� ����
	//str.length() �� �����Ϸ����� �ٸ� - �Ϻ� �����Ϸ������� ���� ī����
	//���������� O(1) - �ݺ����� ���� -> size ������ �����ϰ� �ֱ� ����
	cout << a.size() << ' ' << a.length() << endl;

	//����
	//���������� ���ڿ� ���̸�ŭ �ݺ� - but, �ſ� ���� ��
	string c = b;

	//���ڿ� 2���� �̾���̱�
	//2�� �߿� �ϳ��� string �̾�� ���� ����
	//ex. "123" + "ABC" �Ұ�
	string d = a + b;

	//insert() - ���� �߰�
	//���������� ���ڿ� ���̸�ŭ �ݺ� - ���Ҹ� �߰��� �� �� �ڷ� �о��ִ� �۾�

	//find() - ���� ã��
	//�ش� �ε����� ��ȯ
	//string::npos - ã�� ���� ���

	//erase() - ����
	//replace() - ġȯ


	return 0;
}