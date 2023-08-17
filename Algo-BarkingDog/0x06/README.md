[큐](https://blog.encrypted.gg/932)

## 시간 복잡도

원소 추가/제거 - O(1)

제일 상단의 원소 확인 - O(1)

[큐](https://blog.encrypted.gg/934)

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
