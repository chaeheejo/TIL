# 연결 리스트

[문제집 링크](https://www.acmicpc.net/workbook/view/7308)

[블로그 링크](https://blog.encrypted.gg/932)

| 문제 분류 | 문제 | 문제 제목 | 정답 코드 | 풀이 여부 |
| :--: | :--: | :--: | :--: | :--: |
| 연습 문제 | 1406 | [에디터](https://www.acmicpc.net/problem/1406) | [정답 코드](../0x04/solutions/1406.cpp) | O |
| 기본 문제✔ | 5397 | [키로거](https://www.acmicpc.net/problem/5397) | [정답 코드](../0x04/solutions/5397.cpp) | O |
| 기본 문제✔ | 1158 | [요세푸스 문제](https://www.acmicpc.net/problem/1158) | [정답 코드](../0x04/solutions/1158.cpp), [별해 1](../0x04/solutions/1158_1.cpp), [별해 2](../0x04/solutions/1158_2.cpp) | O |

---

## 시간 복잡도

K번째 원소를 확인/변경하고자 할 때 - O(K)

임의의 위치에 원소를 추가/제거할 때 - O(1)

### vector와의 차이

|  | list | vector |
| --- | --- | --- |
| 메모리 할당 | 연속적인 메모리 할당 | 비연속적인 메모리 할당 |
| 랜덤 접근 | O(N) | O(1) |
| 삽입 삭제 | O(1) | O(K) - K번째 인덱스에 |

## STL code
```cpp
list<int> L;

L.push_front(1); //1

list<int>::iterator it = L.begin();

L.push_front(2); //2 1

L.push_back(4);
L.push_back(5); //2 1 4 5

L.insert(it, 6); //2 6 1 4 5
it++; //4을 가르킴

it = L.erase(it); //2 6 1 5 - 4를 지우고 5를 가르킴

for(auto i : L) cout<<i<<' ';

for(it = L.begin(); it!=L.end(); it++) cout<<*it<<' ';
```
