### 화살표 함수 
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

---
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

### reduce

```jsx
const array = [1,2,3,4,5]

//1+2+3+4+5
const result = array.reduce((acc, cur)=>{
	acc+=cur
	return acc
}, 0)

//[11,12,13,14,15]
const result2 = array.reduce((acc, cur)=>{
	acc.push(cur+10)
	return acc
}, [])
```

acc에 계산 값을 담아 출력

cur은 배열의 원소 중 현재 값

acc의 형태는 숫자, 문자, 배열, 빈 객체

### reduce == map

```jsx
const array = [1,2,3,4,5]

const resultReduce = array.reduce((acc, cur)=>{
	acc.push(cur*cur)
	return acc
},[])

const resultMap = array.map(element => (element*element))
```

### reduce == count

```jsx
const array = [1,2,2,3,3,4,5]

const result = array.reduce((acc, cur)=>{
	if(acc[cur]){
		acc[cur] += 1
	}
	else{
		acc[cur] = 1
	}
	return acc
}, {})
```
---
### 백틱 ``

백틱을 사용해 script로 html tag 안에 특정 value를 넣을 수 있음

```jsx
const a = "pppp";
const htmlTag = `
<button>
    안녕하세요
    ${a}
</button>
`;
document.body.insertAdjacentHTML('beforeend', htmlTag);
```

a의 값이 htmlTag 안으로 들어감

```jsx
const bucketLists = [
    {id:3, text:"여행가기", done:false},
    {id:2, text:"치킨 먹기", done:true},
    {id:1, text:"코딩 하기", done:false},
]

function render(){
    let html =``
    bucketLists.forEach(bucketList=>{
        html += `<li id="${bucketList.id}"><label>
            <input type="checkbox">${bucketList.text}
            </label>
            </li>`
    })
}

console.log(render())
```
---

### 비구조할당 - **destructuring**

```jsx
//배열을 순서가 보장되어 있기 때문에 변수 이름만으로 비구조할당 가능
const array = [1,2];
const [one, two] = array;

//객체는 원래 객체에 선언된 이름이 아니면 각각 비구조할당
const abc = {name: "a", type: "b"}
const {name, type} = abc

const {name: who, type: what} = abc
```

### spread

```jsx
const sub = { row: 10, col: 20}
const main = {...sub, color: "red"}
```

### rest

```jsx
const person = {height: 180, age: 20, name: "jo"}
//another에는 age, name에 대한 정보가 들어간다.
const {height, ...another} = person
const {height: howTall, ...another} = person

const array = [1,2,3,4,5]
//want에는 [3,4,5]
const {one, two, ...want} = array
```
---
### 객체 안에 함수 정의하기

```jsx
const obj = {
	width: 200,
	getHeight: function(){
		alert("300")
	}
}

const obj = {
	width: 200,
	getHeight(){
		return this.width+10
	}
}
```

객체를 const로 정의하면 call stack에 저장되어 변경을 막는다.

그러나 객체의 변수들은 heap에 저장되므로 객체를 const로 정의해도 객체 안의 값을 변경할 수 있다.

### callback function

```jsx
function run(e){ //callback func
	console.log("pressed")
}

document.addEventListener("keyup", run)
```
