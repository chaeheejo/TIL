## HTML
> Hyper Text Markup Language  

<br>

head : 문서에 대한 정의, title, css 내용이 들어간다.

body : 실제 문서에 대한 내용, html과 script 내용이 들어간다.

### 문서 타이틀

```jsx
<head>
    <title>Document</title>
</head>
```

1. H 태그는 숫자가 낮을수록 중요도가 높아짐
2. ul : unordered list 순서가 없는 리스트
    
    ol : ordered list 순서가 있는 리스트
    
    ol>li*3 : ol 안에 li 태그 3개가 만들어짐
    
3. p 문단 태그 - 단순히 문단 나누는 용도
4. input 입력 태그
    1. type : radio, checkbox, submit, button
    2. placeholder - 입력을 하기 전 값
    3. value - 입력을 하지 않았을 때 default 값
5. 페이지 안에 웹 사이트 넣기 iframe
6. form : 입력폼을 전송하기 위한 양식
7. select & option - 다중 선택 태그
8. div : division의 약자, 형식상 나누는 용도

### 시멘틱 웹

: 검색엔진 최적화, 스크린 리더 활용

---

## CSS

> Cascading Style Sheets

### name

div.font-wrapper : div의 클래스 이름 font-wrapper

div#test : div의 클래스 id test

### css 첨부 방법

1. head에서 style 태그 열기
2. body에서 직접 style 속성 달기
3. 외부 css 파일 첨부하기

### css 선택자

1. all *
2. div / span 등 태그 이름으로
3. class - 중복 값 가능 [.class_name]
    - 하나의 태그에 다중 클래스 부여 가능
    - ex. div class = “my-class aa”
4. id - 중복 id 값 불가 [#id_name]

선택자의 우선순위가 있음

### margin, padding

margin은 바깥 여백, padding은 안쪽 여백

### 배경 이미지 삽입

cover - 배경 요소를 가득 채우도록 이미지를 확대, 축소

contain - 가로, 세로 비율을 맞춰서 확대, 축소

### 상속

자식 태그, 안쪽 태그는 부모 태그, 바깥 태그의 style 값을 상속 받음

### inline vs block

inline 요소는 나란히 배열

- width, height, margin top, bottom 지정 불가
- span a

block은 한 칸씩 배열

- div p h

block에 display=inline 속성을 줄 수 있음

inline-block이라는 속성도 있음 - inline의 단점을 보완한 형태
- 전후 줄 바꿈 없음 그러나 width, height 지정 가능
- button select

### display: flex

부모 안에서 자식들을 정렬하고 싶을 때

justify-content : 메인축 정렬

align-items : 교차축 정렬

### position

fixed - 레이아웃을 고정, width가 inline처럼 줄어든다. 브라우저가 기준

relative - 현재 객체가 있는 위치를 기준

absolute - relative 태그를 갖고 있는 부모 기준, 없으면 타고타고 올라가다 브라우저가 기준

### z-index

겹친 객체들끼리의 우선순위를 따지고 싶을 때 사용

3차원 요소에만 유효한 값

값이 클수록 우선순위가 높다.


---

## JS

> JavaScript는 비동기식 프로그래밍 때문에 각광받는다.  
> 과거에는 브라우저마다 지원하는 API가 다르기 때문에 반복 작업이 많았다.  
> 제이쿼리로 다수의 파트를 통합했기에 많은 이들이 사용했다.

### 자료형

선언할 수 있는 키워드는 var, let, const

var은 재선언 가능, 함수레벨 스코프

let, const는 재선언 불가, 블록레벨 스코프

```jsx
var a = 10
var a = 20 //possible

{ //block
	var c = 5;
}
console.log(c) //possible
```

const는 값이 변하지 않는 상수

let은 값이 변하는 변수

### 원시 자료형

number, string, boolean, null, undefined

```jsx
const numberA = 123;

const stringB = "text";

const boolC = true;
```

null은 값이 비어있다고 명시하는 것

typeof(null)가 object라고 정의되는 버그가 있음

왜 못 고칠까? if(type == object) 를 null을 잡기 위한 코드로 작성

undefined는 아직 값을 할당받지 않은 상태를 말함

자바스크립트 엔진이 변수를 초기화할 때 사용함

### 참조 자료형

function, array, object 모두 객체로 취급됨

```jsx
const arrayA = [1,2,3]

const objectB = {a:'A', b:'B'}

const hello = function C(){
	console.log('hello')
}

hello()
```

원시 자료형은 call stack 영역에 저장됨

참조 자료형은 heap에 저장

때문에 const 참조 자료형인 object의 value 값을 바꿀 수 있음

```jsx
const obj = {a:5}
obj.a = 100
```

### 호이스팅

선언 부분을 최상단으로 끌어올리는 것

```jsx
console.log(a);
var a = 10; //possible
```

let과 const는 호이스팅이 동작하는 것을 막는다.

### 함수의 호이스팅

```jsx
test();

function test(){
	console.log("hello world");
}
```

function 자체가 맨 위로 올라감

호출한 뒤에 선언 가능

```jsx
hello(); //error

var hello = function(){
	console.log("test");
}
```

error : not a function

이유는 변수에 함수를 넣은 것이기 때문에 내부적으로는

```jsx
var hello;
hello(); //undefined를 함수로 호출하려 하니 error
hello = function(){
	console.log("hello");
}
```

### const 객체 내부의 값 변경 가능

```jsx
const obj={a:5}
obj.a = 100 //값 변경 가능
```

원시 타입은 call stack에 저장

참조 자료형은 heap에 저장

heap 메모리의 값은 바꿀 수 있기 때문에 변경 가능
