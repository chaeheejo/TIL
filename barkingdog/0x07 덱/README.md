# 덱

[문제집 링크](https://www.acmicpc.net/workbook/view/7311)

[블로그 링크](https://blog.encrypted.gg/935)

| 문제 분류 | 문제 | 문제 제목 | 정답 코드 | 풀이 여부 |
| :--: | :--: | :--: | :--: | :--: |
| 연습 문제 | 10866 | [덱](https://www.acmicpc.net/problem/10866) | [정답 코드](../0x07/solutions/10866.cpp) |
| 기본 문제✔ | 1021 | [회전하는 큐](https://www.acmicpc.net/problem/1021) | [정답 코드](../0x07/solutions/1021.cpp) |
| 응용 문제✔ | 5430 | [AC](https://www.acmicpc.net/problem/5430) | [정답 코드](../0x07/solutions/5430.cpp), [별해 1](../0x07/solutions/5430_1.cpp) | O |
| 응용 문제 | 11003 | [최솟값 찾기](https://www.acmicpc.net/problem/11003) | [정답 코드](../0x07/solutions/11003.cpp), [별해 1](../0x07/solutions/11003_1.cpp) | O |

---

## 시간 복잡도

원소 추가/제거 - O(1)

제일 앞/뒤의 원소 확인 - O(1)

### 자료구조 형태

양쪽 끝에서 삽입, 삭제 모두 가능

## STL code
```cpp
deque<int> dq;

dq.push_front(1); //1
dq.push_back(2); //1 2
dq.push_front(3); //3 1 2

cout << dq.empty() << '\n'; //false
cout << dq.front() << '\n'; //3
cout << dq.back() << '\n'; //2 

dq.front_pop(); //3 - 맨 앞의 원소가 사라짐
dq.back_pop(); //2 - 맨 뒤의 원소가 사라짐

auto it = dq.begin();
it = dq.insert(it, 10); //10 1

it = dp.erase(it); //10

cout << q.size() << '\n'; //1
```
