#include <iostream>
#include <queue>
using namespace std;

#define MAX 20001

struct Node {
    int to; //현재 노드가 가르키고 있는 노드
    int to_cost; //그 노드까지 가는데 필요한 비용

    bool operator<(Node right) const { //가는 비용이 최소인 것을 우선
        if (to_cost < right.to_cost) return false;
        if (to_cost > right.to_cost) return true;
        return false;
    }
};

int N, T;
vector<Node> graph[MAX];
int dist[MAX];

void dijkstra(int start) {
    for (int i = 0; i < N; i++) {
        dist[i] = 1e9;
    }

    priority_queue<Node> pq;
    pq.push({ start,0 });
    dist[start] = 0;
    
    while (!pq.empty()) {
        Node cur_node = pq.top(); //현재 우선순위 큐에 있는 값 중 가는 비용이 가장 최소인 것
        pq.pop();

        if (dist[cur_node.to] < cur_node.to_cost) { //현재 노드의 dist가 업데이트가 이미 된 적이 있으면 pass
            continue;
        }

        for (int i = 0; i < graph[cur_node.to].size(); i++) { //현재 노드의 자식들을 볼거임
            Node next_node = graph[cur_node.to][i]; //자식들 호출

            //만약, 자식에서 자식으로 바로 가는게 현재에서 자식의 자식으로 가는 것보다 빠르면 냅둠
            if (dist[next_node.to] <= dist[cur_node.to] + next_node.to_cost) {
                continue;
            }

            //느리면, 현재에서 자식의 자식으로 가는 게 더 빠르므로 업데이트
            dist[next_node.to] = dist[cur_node.to] + next_node.to_cost;
            //우선순위 큐에는 거리가 짧은 거를 우선으로 업데이트를 해줌
            pq.push({ next_node.to, dist[next_node.to] });
        }
    }

}

int main() {

    cin >> N >> T;

    for (int i = 0; i < T; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;

        graph[from].push_back({ to, cost });
    }

    //0번부터 N-1번 노드까지 가는 최소 비용
    dijkstra(0);

    if (dist[N - 1] == 1e9) {
        cout << "impossible";
    }
    else {
        cout << dist[N - 1];
    }
    return 0;
}
