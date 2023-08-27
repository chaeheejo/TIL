#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v[100];
int visited[100];
int answer;

void dfs(int node) {
    visited[node] = 1;
    for (int i = 0; i < v[node].size(); i++) {
        if (!visited[v[node][i]]) {
            dfs(v[node][i]);
        }
    }
}

int main() {

    cin >> N;

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int from, to;
        cin >> from >> to;

        from -= 1;
        to -= 1;

        v[from].push_back(to);
        v[to].push_back(from);
    }

    dfs(0);

    for (int i = 0; i < 100; i++) {
        answer += visited[i];
    }

    cout << answer-1;

    return 0;
}
