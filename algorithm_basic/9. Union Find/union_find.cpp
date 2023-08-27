#include <iostream>
using namespace std;

//Union-Find를 적용해 푸는 문제
//조건 1. 그룹을 합쳐가는 과정(그룹을 쪼개지 않음)
//조건 2. disjoint-set(서로소 집합 - 교집합이 없음)

//문제 유형
//1. 그룹 data 관리 - 그룹에 몇 명이 있는지 관리 - 해당 그룹의 data는 모두 대표에게 저장
//                    cnt[10] 배열에 index를 그룹 번호, value를 해당 그룹에 속한 인원 수로 관리
//                    Union에서 update
//2. 경로 단축 - 대표까지의 경로를 단축하는 문제 - 중간 단계가 필요하지 않고, 최종 단계만 필요할 때
//3. 그룹을 끊어가는 과정 - 끊는 순서를 역순으로 이어보면서 진행

//각각의 부모 저장
int parent[10];

//A가 속한 그룹의 대표 찾기
int Find(int A) {
    //자기 자신이 부모이면 대표
    if (parent[A] == A)
        return A;

    //부모를 타고타고 올라가야 함
    //대표를 찾고 다시 내려올 때는 parent 배열에 대표를 기록하며 내려옴
    //한번은 대표까지 찾아야 모든 자식들이 대표를 가르킴
    return parent[A] = Find(parent[A]);
}

//A가 속한 그룹과 B가 속한 그룹을 합치기
void Union(int A, int B) {
    int rootA = Find(A);
    int rootB = Find(B);

    //rootB를 rootA 밑으로
    //(문제의 조건에 맞게 설정 ex. 각 대표는 가장 작은 번호가 차지한다.)
    parent[rootB] = rootA;
}

int cnt[10];
void cntUnion(int A, int B) {
    int rootA = Find(A);
    int rootB = Find(B);

    if (rootA == rootB) return;

    parent[rootB] = rootA;
    cnt[rootA] += cnt[rootB];
    cnt[rootB] = 0;
}

int main() {

    int cntNode;
    int cntQuery;

    cin >> cntNode >> cntQuery;

    //parent 세팅 - 각자가 대표, 전부 1인 그룹
    for (int i = 0; i < 10; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < cntQuery; i++) {
        int A, B;
        cin >> A >> B;

        Union(A, B); //A와 B가 같은 그룹에 속함
    }

    for (int i = 1; i <= cntNode; i++) {
        cout << i << ": " << Find(i) << "\n";
    }

    return 0;
}
