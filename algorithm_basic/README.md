1초당 1억번까지는 안전한 시간이다.

---

## DAT

DAT : Direct Access Table

1초당 1억번까지는 안전한 시간이다.

배열의 인덱스에 의미를 부여한 것 (HashMap의 배열화 버전)

---

## Graph

graph를 저장하는 방법 : 인접 행렬, 인접 리스트

1. 인접 행렬 : DAT[a][b] = 1
    
2. 인접 리스트 : vector<int> graph[nodeNum]
 
---

## BFS - 너비 우선 탐색

> 루트 노드에서 시작해 인접한 노드를 먼저 탐색하는 기법

큐와 visited 배열을 사용해 구현

문제 유형 : 최단 경로

---

## DFS - 깊이 우선 탐색

> 루트 노드에서 시작해 리프 노드에 도달할 때까지 탐색하는 기법

재귀를 사용해 구현, 탈출 조건은 backtracking

문제 유형 : 순열, 조합 등 모든 경우를 탐색해야 하는 완전 탐색 문제 or 깊이가 정해져 있는 그래프 탐색

---

## Backtracking

> 퇴각 검색, 현재 상태가 유망하지 않으면 다음으로 진행하지 않고 종료

구현 : DFS 알고리즘과 함께 사용

---

## Sort, Priority Queue

sort : 배열의 모든 요소를 줄 세움 

단점) 모든 요소를 정렬하는 데 드는 시간 O(N logN)

우선순위 큐 : 최상위 노드에 반환하는 시간 O(1) and 노드를 정렬하는 시간 O(logN)

단점) 모든 요소는 줄 세우지 않아 pop and sort를 반복해야 함

---

## Heap

> 완전 이진 트리 형태로 우선순위 큐를 위해 고안된 자료구조

최대힙 : 부모는 항상 자식보다 큰 값

최소힙 : 부모는 항상 자식보다 작은 값

---

## Dijkstra

> 노드 사이에 이동 비용(가중치)이 가장 적은 경로를 찾는 알고리즘

BFS의 변형

기본적으로는 BFS를 기반으로 탐색을 진행

우선순위 큐를 활용해 비용이 적은 노드를 우선적으로 탐색

---

## Union Find

> 두 그룹을 합치고, 해당 노드가 해당 그룹에 속해있는지 찾기

각각의 그룹은 그룹의 대표로 표현한다. (한 그룹 당 한 명의 대표만 있다.)

Union(A, B)의 의미는 A점이 속한 그룹의 대표와 B점이 속한 그룹의 대표를 합쳐라

---

## MST(Minimum Spanning Tree)

간선의 가중치 합이 최소인 트리

### Kruskal Algorithm

> 각 단계에서 노드를 하나씩 연결해나가는 방법
> 
- 최소의 비용, 같은 그룹에 속하지 않으면 연결

### Prim Algorithm

> 작은 가중치 순서대로 퍼져나감
> 
- BFS에서 작은 가중치 순으로
- dijkstra와 다른 점
    - dijkstra는 시작점으로부터의 비용 순서대로
    - Prim은 현재 위치에서부터 적은 비용 순서대로

### 시간복잡도

Kruskal : cntEdge log (cntEdge) == cntEdge log (cntVertex)

Prim : cntEdge log (cntEdge) == cntEdge log (cntVertex)

### 차이점

Kruskal은 선을 기반으로 탐색

→ 모든 선을 전부 한번에 알고 있어야 함

Prim은 점을 기반으로 탐색

---

## Two Pointer

두 개의 위치를 가르키는 것

배열의 연속된 구간에서 원소의 합이 114인 곳은?

- left, right 두 개의 포인터를 처음에 0번 인덱스부터 시작
- left와 right가 가르키고 있는 곳의 합을 계산
- sum이 114보다 작으면 right 증가
- 크면 left 증가

### 시간복잡도

O(N)

---

## Sequence container

연속적인 메모리 할당

- Array
- Vector
- deque
- List

## Associative Container

관계형 구조

- Set : collection of unique data, sorted by data
    - 중복된 데이터는 넣을 수 없다.
- Map : collection of key-value pairs, sorted by keys, keys are unique

## Unordered Associative Container

- Hash Map

## Container Adaptor

기존의 구조를 사용해 만든 컨테이너

- queue
- priority_queue
- stack

### Set

### 시간 복잡도

- insert, find, erase : logN
- lower_bound, upper_bound : logN
- clear, size : 1

--- 

## DP의 두 가지 방식

top-down 방식은 next들을 보고 now를 결정 - DFS 기반

bottom-up 방식은 prev들을 보고 now를 결정 - for문 기반

## TOP-DOWN

1. 기본 dfs
    - now→next로 가는 구조
2. 반환 받아 처리 받는 구조
    - dfs(now) : now에서 E까지의 결과
3. dp라는 배열에 저장
    - 이미 계산한 적이 있는 now면 그대로 return

## BOTTOM-UP
1. 순서를 명확하게 선정
2. now를 계산하기 위한 prev 만들기
    - prev→now에 해당하는 prev 찾기
3. 계산 결과를 dp 배열에 저장

### 주의해야 할 점

계산을 진행하면서 바뀔 수 있는 것들을 DFS에서의 매개변수, dp의 index로 설정

ex. 좌표
