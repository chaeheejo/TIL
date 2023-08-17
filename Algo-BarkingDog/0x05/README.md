[스택](https://blog.encrypted.gg/932)

## 시간 복잡도

원소 추가/제거 - O(1)

제일 상단의 원소 확인 - O(1)

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
