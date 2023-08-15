[기초 코드 작성 요령](https://blog.encrypted.gg/922)

## 시간복잡도

O(1) < O(logN) < O(N) < O(NlogN) < O(N^2) < O(2^N) < O(N!)

| N의 크기 | 허용 시간복잡도 |
| --- | --- |
| N≤11 | O(N!) |
| N≤25 | O(2^N) |
| N≤100 | O(N^4) |
| N≤500 | O(N^3) |
| N≤3,000 | O(N^2logN) |
| N≤5,000 | O(N^2) |
| N≤1,000,000 | O(NlogN) |
| N≤10,000,000 | O(N) |
| 그 이상 | O(logN), O(1) |

---
## 표준 입출력

### cin / cout

cin, cout은 char*와 string 처리가 가능하나

scanf, printf는 string 처리 불가

### getline

공백이 포함된 한 줄의 문자열을 받고 싶을 때

### 입출력 시간초과 방지

```cpp
ios::sync_with_stdio(0);
cin.tie(0);
```

cin, cout을 사용할 때에는 입출력 지연으로 시간 초과 발생 가능

endl 대신 ‘\n’ 사용

---

### 실수 자료형

double 이용 - float보다 오차가 적다.

실수를 사용해야 하는 문제는, 문제에 절대/상대 오차가 주어진다.

실수를 비교할 때에는 등호를 사용하면 안된다. - 예상한 대로 비교해주지 않음 - why? 실수를 표기하는 방식
