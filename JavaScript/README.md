## 화살표 함수
### 기본 format
```jsx
const normal = function() {
	console.log('normal function')
}

const arrow = (param1, param2) => {
	function code
}

const arrow2 = (a, b) => { a+b }
const result = arrow2(1,2)
```

화살표함수는 항상 무명 메소드이다.

return 가능

```jsx
const b = () =>{
    console.log("화살표");
}
b();

const c = () => console.log("화살표");

const plus = (a,b) =>{
    return a+b;
}
const result = plus(3,5);

//plus와 같은 함수
//블럭이 없으면 바로 return
const plus2 = (a,b) => a+b
```

화살표 함수는 호이스팅이 안된다.

선언한 이후에 호출해야 된다.

### callback function

```jsx
function run(e){ //callback func
	console.log("pressed")
}

document.addEventListener("keyup", run)
```

## 배열 메소드

### forEach - 배열 탐색

```jsx
const array = [1,2,3,4,5]

array.forEach(element =>{
	if(element%2==0)
		console.log(element)
})
```

### some - 조건 확인 (하나라도 맞니?)

```jsx
const array = [1,2,3,4,5]

console.log(array.some(element => element==5)) //true
```

화살표 함수의 내용은 조건

배열의 한 요소라도 조건을 만족하면 true 반환 / 모두 만족 안한다면 false

### every - 조건 확인 (모두 맞니?)

```jsx
const array = [1,2,3,4,5]

console.log(array.every(element => element==5)) //false
```

배열의 모든 요소가 조건을 만족하면 true

### find - 조건을 만족하는 첫번째 요소

```jsx
const array = [1,2,3,4,5]

array.find(element => element==5) //5
```

### findIndex - 조건을 만족하는 첫번째 요소의 인덱스

```jsx
const array = [1,2,3,4,5]

array.findIndex(element => element==5) //5
```

### map - 배열의 각 요소에 새로운 규칙 적용

```jsx
const array = [1,2,3,4,5]

//[true, true, true, false, false]
const newArray = array.map(element => element<3)

//[2,3,4,5,6]
const result = array.map(element => element+1)
```

forEach와 map 모두 배열의 요소를 하나씩 방문하는 함수

But, map은 새로운 규칙으로 새로운 배열을 생성해 반환

### filter - 특정 조건에 맞는 요소들만 배열로

```jsx
const array = [1,2,3,4,5]

//[1,2]
const newArray = array.filter(element => element<3)
```
