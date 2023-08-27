# 큐

[문제집 링크](https://www.acmicpc.net/workbook/view/7310)

[블로그 링크](https://blog.encrypted.gg/934)

| 문제 분류 | 문제 | 문제 제목 | 정답 코드 | 풀이 여부 |
| :--: | :--: | :--: | :--: | :--: |
| 연습 문제 | 10845 | [큐](https://www.acmicpc.net/problem/10845) | [정답 코드](../0x06/solutions/10845.cpp) | O |
| 기본 문제✔ | 18258 | [큐 2](https://www.acmicpc.net/problem/18258) | [정답 코드](../0x06/solutions/18258.cpp), [별해 1](../0x06/solutions/18258_1.cpp) |
| 기본 문제✔ | 2164 | [카드2](https://www.acmicpc.net/problem/2164) | [정답 코드](../0x06/solutions/2164.cpp) | O |

---

## 시간 복잡도

원소 추가/제거 - O(1)

제일 앞/뒤의 원소 확인 - O(1)

### 자료구조 형태

FIFO (First - In - First - Out)

## STL code
```cpp
queue<int> q;

q.push(1);
q.push(2);

cout << q.empty() << '\n'; //false
cout << q.front() << '\n'; //1
cout << q.back() << '\n'; //2 

q.pop(); //2 - 맨 앞의 원소가 사라짐

cout << q.size() << '\n'; //1
```
