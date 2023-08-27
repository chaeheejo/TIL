#include <iostream>
using namespace std;

//함수 공통으로 사용 -> 전역 변수로 사용

void func(int n) {
    //2. 끝낼 조건
    if (n == 9) {
        //3.3 끝에서 출력
        cout << n;
        return;
    }

    //3-1. 다음박스로 진행해 가면서 작업
    cout << n;

    //1. 재귀 기본 구조 - 자기 자신 호출
    func(n + 1);

    //3-2. 다음박스로 갔다 돌아오면서 작업
    cout << n;
}
