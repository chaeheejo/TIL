#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring> //char[] 기반
#include <string> //string

using namespace std;

int main() {

	//strcmp, strlen, strcpy, memset

	char str1[100] = "ABC";
	char str2[100] = "DEF";

	//strcmp - 문자열 비교
	//str1이 사전순으로 빠른 경우 : return 음수
	//두 문자가 같은 경우 : return 0
	//str2가 사전순으로 빠른 경우 : return 양수
	//내부적으로 str1, str2를 문자열 개수만큼 반복
	cout << strcmp(str1, str2) << "\n";

	//strlen - 문자열의 길이
	//내부적으로 NULL(='\0' =0(ascii code) =false)을 만날 때까지
	//문자열 개수만큼 반복
	cout << strlen(str1) << "\n";

	//strcpy - 문자열을 복사
	char str3[100];
	strcpy(str3, str2);
	cout << str3 << "\n";

	//memset - data를 통째로 세팅
	//초기화할 때 많이 씀
	//주의 - 바이트 단위로 값을 넣기에 4바이트인 int형에는 원하는 값이 안 들어감
	//memset은 int 배열에서 0이나 -1로 초기화할 때 사용
	//내부적으로 배열의 길이만큼 반복
	int arr[100];
	memset(arr, 0, sizeof(arr));
	memset(arr, -1, sizeof(arr));

	for (int i = 0; i < 100; i++) {
		arr[i] = -1;
	} //과 다를게 없음
	//algorithm 라이브러리의 fill 함수는 원하는 값을 넣어줌(int형)
	

	//string은 char 배열이랑 다름
	string str = "1234";
	char str5[100] = "123";
	//string은 NULL 없이 데이터가 저장, char 배열은 NULL로 마지막을 구분
	//NULL이 들어가지 않은 이유 : string은 데이터의 크기를 size로 접근할 수 있음

	//사전순 비교 부등호로
	//내부적으로 문자열 길이만큼 반복
	string a = "ABC";
	string b = "ABB";
	if (a > b) {
		cout << "a가 사전순으로 빠름\n";
	}

	//문자열 길이
	//str.length() 가 컴파일러마다 다름 - 일부 컴파일러에서는 직접 카운팅
	//내부적으로 O(1) - 반복하지 않음 -> size 변수를 관리하고 있기 때문
	cout << a.size() << ' ' << a.length() << endl;

	//복사
	//내부적으로 문자열 길이만큼 반복 - but, 매우 빠른 편
	string c = b;

	//문자열 2개를 이어붙이기
	//2개 중에 하나는 string 이어야 연산 가능
	//ex. "123" + "ABC" 불가
	string d = a + b;

	//insert() - 원소 추가
	//내부적으로 문자열 길이만큼 반복 - 원소를 중간에 낄 때 뒤로 밀어주는 작업

	//find() - 원소 찾기
	//해당 인덱스를 반환
	//string::npos - 찾지 못한 경우

	//erase() - 삭제
	//replace() - 치환


	return 0;
}