#include <iostream>
#include <algorithm>
using namespace std;

// Kruskal algorithm
//1. Edge를 저장
//2. Edge를 정렬
//3. Edge를 순서대로 연결 - 이미 연결된 점끼린 연결하지 않음 - Union Find 활용

struct Edge {
    int cost;
    int A, B;

    bool operator<(const Edge right) const {
        if (cost < right.cost) return true;
        if (cost > right.cost) return false;

        if (A < right.A) return true;
        if (A > right.A) return false;

        if (B < right.B) return true;
        if (B > right.B) return false;
        
        return false;
    }
};

Edge edges[20];
int parent[20];

int Find(int A) {
    if (parent[A] == A)
        return A;
    return parent[A] = Find(parent[A]);
}

void Union(int A, int B) {
    int rootA = Find(A);
    int rootB = Find(B);
    parent[rootA] = rootB;
}

int main() {

    int cntNode, cntEdge;
    cin >> cntNode >> cntEdge;

    //1. Edge 저장
    for (int i = 0; i < cntEdge; i++) {
        int A, B, cost;
        cin >> A >> B >> cost;
        edges[i] = { cost,A,B };
    }

    //2. Edge 정렬
    sort(edges, edges + cntEdge);

    //3-1. parent 초기화
    for (int i = 0; i < cntNode; i++) {
        parent[i] = i;
    }

    int sum = 0;
    for (int i = 0; i < cntEdge; i++) {
        Edge now = edges[i];

        //이미 같은 그룹이면 둘이 연결하지 않음 - 사이클이 없도록
        if (Find(now.A) == Find(now.B)) {
            continue;
        }

        Union(now.A, now.B);
        sum += now.cost;
    }
    cout << sum;

    return 0;
}
