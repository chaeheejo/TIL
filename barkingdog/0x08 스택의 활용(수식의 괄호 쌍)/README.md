# 스택의 활용(수식의 괄호 쌍)

[문제집 링크](https://www.acmicpc.net/workbook/view/7312)

[블로그 링크](https://blog.encrypted.gg/936)

| 문제 분류 | 문제 | 문제 제목 | 정답 코드 | 풀이 여부 |
| :--: | :--: | :--: | :--: | :--: |
| 연습 문제 | 4949 | [균형잡힌 세상](https://www.acmicpc.net/problem/4949) | [정답 코드](../0x08/solutions/4949.cpp) | O |
| 기본 문제✔ | 3986 | [좋은 단어](https://www.acmicpc.net/problem/3986) | [정답 코드](../0x08/solutions/3986.cpp) | O |
| 기본 문제 | 9012 | [괄호](https://www.acmicpc.net/problem/9012) | [정답 코드](../0x08/solutions/9012.cpp) | O |
| 응용 문제✔ | 10799 | [쇠막대기](https://www.acmicpc.net/problem/10799) | [정답 코드](../0x08/solutions/10799.cpp) | O |
| 응용 문제✔ | 2504 | [괄호의 값](https://www.acmicpc.net/problem/2504) | [정답 코드](../0x08/solutions/2504.cpp) |

--- 

## 문제 해결 방법

1. 여는 괄호가 나오면 스택에 추가
2. 닫는 괄호가 나왔을 경우,
    1. 스택이 비어있으면 올바르지 않은 괄호 쌍
    2. 스택의 top이 짝이 맞지 않은 괄호일 경우 올바르지 않은 괄호 쌍
    3. 스택의 top이 짝이 맞는 괄호일 경우 pop
3. 모든 과정을 끝낸 후 스택에 괄호가 남아있으면 올바르지 않은 괄호 쌍, 남아있지 않으면 올바른 괄호 쌍
