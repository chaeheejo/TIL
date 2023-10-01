//
//  start_link.cpp
//  algorithm
//
//  Created by chaehee on 2023/10/01.
//

#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;
int map[1000001];

int bfs() {
    queue<int> q;
    q.push(S);
    map[S] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == G) {
            return map[cur];
        }

        if (cur - D > 0 && map[cur - D] == 0) {
            map[cur - D] = map[cur] + 1;
            q.push(cur - D);
        }
        if (cur + U <= F && map[cur + U] == 0) {
            map[cur + U] = map[cur] + 1;
            q.push(cur + U);
        }
    }
    return -1;
}

int main() {

    cin >> F >> S >> G >> U >> D;

    int answer = bfs();
    if (answer == -1) {
        cout << "use the stairs";
    }
    else {
        cout << answer-1;
    }

    return 0;
}
