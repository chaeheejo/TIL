#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Prim Algorithm
//1. 그래프를 저장 - 인접행렬, 인접 리스트를 기반으로 저장
//2. 우선순위 큐를 통해 가중치가 적은 노드를 우선적으로 방문
//3. 맨처음 시작점은 아무 점에서나 시작 가능
//4. 큐에서 꺼낸 점은 트리에 합쳐지고, 인접한 노드들이 큐에 들어감

struct Edge {
    int to;
    int cost;

    bool operator <(const Edge right) const {
        if (cost < right.cost) return false;
        if (cost > right.cost) return true;

        if (to < right.to) return false;
        if (to > right.to) return true;

        return false;
    }
};

int main() {
    //from은 인덱스로 활용
    //v[0]에는 0에서 갈 수 있는 노드와 비용이 저장
    vector<Edge> v[20];

    int cntNode, cntEdge;
    cin >> cntNode >> cntEdge;

    for (int i = 0; i < cntEdge; i++) {
        int A, B, cost;
        cin >> A >> B >> cost;

        v[A].push_back({ B, cost });
        v[B].push_back({ A,cost });
    }

    priority_queue<Edge> pq;
    int visited[20] = { 0, };

    int start = 5;
    for (int i = 0; i < v[start].size(); i++) {
        Edge next = v[start][i];
        pq.push(next);
    }

    int sum = 0;

    while (!pq.empty()) {
        Edge now = pq.top();
        pq.pop();
        int nowNode = now.to;

        if (visited[nowNode]) {
            continue;
        }

        visited[nowNode] = 1;
        sum += now.cost;

        for (int i = 0; i < v[nowNode].size(); i++) {
            Edge nextEdge = v[nowNode][i];
            pq.push(nextEdge);
        }
    }

    cout << sum;


    return 0;
}
