[덱](https://blog.encrypted.gg/935)

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
