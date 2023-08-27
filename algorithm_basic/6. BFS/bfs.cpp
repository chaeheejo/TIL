#include <iostream>
#include <queue>
using namespace std;

int visited[100001] = { 0, };
int N, M, K;
vector<int> graph[100001];
int answer;

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        answer++;

        for (int i = 0; i < graph[cur].size(); i++) {
            int nxt = graph[cur][i];
            if (visited[nxt] == 0) {
                visited[nxt] = 1;
                q.push(nxt);
            }
        }
    }
}

int main() {

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int start;
    cin >> start;

    bfs(start);

    cout << answer-1;

    return 0;
}
