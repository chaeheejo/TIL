[연결 리스트](https://blog.encrypted.gg/932)

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
