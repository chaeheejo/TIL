# 스택

[문제집 링크](https://www.acmicpc.net/workbook/view/7309)

[블로그 링크](https://blog.encrypted.gg/933)

| 문제 분류 | 문제 | 문제 제목 | 정답 코드 | 풀이 여부 |
| :--: | :--: | :--: | :--: | :--: |
| 연습 문제 | 10828 | [스택](https://www.acmicpc.net/problem/10828) | [정답 코드](../0x05/solutions/10828.cpp) |
| 기본 문제✔ | 10773 | [제로](https://www.acmicpc.net/problem/10773) | [정답 코드](../0x05/solutions/10773.cpp) | O |
| 응용 문제✔ | 1874 | [스택 수열](https://www.acmicpc.net/problem/1874) | [정답 코드](../0x05/solutions/1874.cpp) |
| 응용 문제✔ | 2493 | [탑](https://www.acmicpc.net/problem/2493) | [정답 코드](../0x05/solutions/2493.cpp) | O |
| 응용 문제 | 6198 | [옥상 정원 꾸미기](https://www.acmicpc.net/problem/6198) | [정답 코드](../0x05/solutions/6198.cpp) | O |
| 응용 문제 | 17298 | [오큰수](https://www.acmicpc.net/problem/17298) | [정답 코드](../0x05/solutions/17298.cpp) | O |
| 응용 문제 | 3015 | [오아시스 재결합](https://www.acmicpc.net/problem/3015) | [정답 코드](../0x05/solutions/3015.cpp) |
| 응용 문제 | 6549 | [히스토그램에서 가장 큰 직사각형](https://www.acmicpc.net/problem/6549) | [정답 코드](../0x05/solutions/6549.cpp) |

---

## 시간 복잡도

원소 추가/제거 - O(1)

제일 상단의 원소 확인 - O(1)

### 자료구조의 형태

LIFO (Last - In - First Out)

## STL code
```cpp
stack<int> st;

st.push(1);
st.push(2);

cout << st.empty() << '\n'; //false
cout << st.top() << '\n'; //2

st.pop(); //return value 없음

cout << st.size() << '\n'; //1
```
