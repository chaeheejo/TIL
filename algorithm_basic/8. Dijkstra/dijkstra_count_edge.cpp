#include <iostream>
#include <queue>
using namespace std;

#define MAX 101

struct Node {
    int to;
    int cost;

    bool operator<(const Node right) const {
        if (cost < right.cost) return false;
        else if (cost > right.cost) return true;
        return false;
    }
};

int N, K, M;
vector<Node> graph[MAX];
int dist[MAX]; //최소 비용
int num[MAX]; //거쳐가는 최소 점의 개수

void dijkstra(int start) {
    for (int i = 0; i <= N; i++) {
        dist[i] = 1e9;
        num[i] = 1e9;
    }

    dist[start] = 0;
    num[start] = 1;

    priority_queue<Node> q;
    q.push({ start,0 });
    while (!q.empty()) {
        Node cur = q.top();
        int cur_to = cur.to;
        int cur_cost = cur.cost;
        q.pop();

        if (dist[cur_to] < cur_cost) {
            continue;
        }

        for (int i = 0; i < graph[cur_to].size(); i++) {
            Node next = graph[cur_to][i];
            int next_to = next.to;
            int next_cost = next.cost;

            if (dist[next_to] <= dist[cur_to] + next_cost) {
                if (dist[next_to] == dist[cur_to] + next_cost && num[next_to] > num[cur_to] + 1) {
                    num[next_to] = num[cur_to] + 1;
                }
                continue;
            }
            
            num[next_to] = num[cur_to] + 1;
            dist[next_to] = dist[cur_to] + next_cost;
            q.push({ next_to, dist[next_to] });
        }
    }
}

int main() {

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;

        graph[from].push_back({ to, cost });
    }

    //1번부터 N번 노드까지 가는 최소 비용
    dijkstra(1);

    if (dist[N] == 1e9) {
        cout << -1;
    }
    else {
        cout << dist[N] << ' ' << num[N];
    }

    return 0;
}
