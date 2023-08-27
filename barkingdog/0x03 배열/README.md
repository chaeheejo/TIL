# 배열

[문제집 링크](https://www.acmicpc.net/workbook/view/7307)

[블로그 링크](https://blog.encrypted.gg/927)

| 문제 분류 | 문제 | 문제 제목 | 정답 코드 | 풀이 여부 |
| :--: | :--: | :--: | :--: | :--: |
| 연습 문제 | 10808 | [알파벳 개수](https://www.acmicpc.net/problem/10808) | [정답 코드](../0x03/solutions/10808.cpp) |
| 기본 문제✔ | 2577 | [숫자의 개수](https://www.acmicpc.net/problem/2577) | [정답 코드](../0x03/solutions/2577.cpp) |
| 기본 문제✔ | 1475 | [방 번호](https://www.acmicpc.net/problem/1475) | [정답 코드](../0x03/solutions/1475.cpp) |
| 기본 문제✔ | 3273 | [두 수의 합](https://www.acmicpc.net/problem/3273) | [정답 코드](../0x03/solutions/3273.cpp), [별해 1](../0x03/solutions/3273_1.cpp) |
| 기본 문제 | 10807 | [개수 세기](https://www.acmicpc.net/problem/10807) | [정답 코드](../0x03/solutions/10807.cpp) |
| 기본 문제 | 13300 | [방 배정](https://www.acmicpc.net/problem/13300) | [정답 코드](../0x03/solutions/13300.cpp) |
| 기본 문제 | 11328 | [Strfry](https://www.acmicpc.net/problem/11328) | [정답 코드](../0x03/solutions/11328.cpp) |
| 기본 문제 | 1919 | [애너그램 만들기](https://www.acmicpc.net/problem/1919) | [정답 코드](../0x03/solutions/1919.cpp) |


---

## 메모리 할당

연속된 메모리를 할당받아야 하기 때문에 메모리 상 제약이 있을 수 있다.

### 시간 복잡도

해당 index의 값 확인/변경 - O(1)

원소 끝에 추가 - O(1)

마지막 원소 제거 - O(1)

임의의 위치에 원소를 추가/제거 - O(N)

: 새로운 원소를 추가하거나 제거하는 데 걸리는 시간이 많다.

### 배열의 원소를 같은 값으로 초기화

1. memset - 0과 -1만 사용할 수 있음 [비추]
2. for문으로 하나하나 전부 접근해 바꾸는 방식
3. algorithm STL의 fill 함수

## STL vector

### 시간 복잡도

push_back, pop_back - O(1)

insert, erase - O(N)
