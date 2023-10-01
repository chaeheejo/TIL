//
//  create_password.cpp
//  algorithm
//
//  Created by chaehee on 2023/10/01.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
vector<char> v;
vector<char> path;

bool check() {
    int cnt = 0;
    for (int i = 0; i < path.size(); i++) {
        if (path[i] == 'a' || path[i] == 'e' || path[i] == 'i' || path[i] == 'o' || path[i] == 'u') {
            cnt++;
        }
    }

    if (cnt >= 1 && L - cnt >= 2) {
        return true;
    }
    return false;
}

void dfs(int cur) {
    if (path.size() == L) {
        if (check()) {
            for (int i = 0; i < path.size(); i++) {
                cout << path[i];
            }
            cout << "\n";
        }
        return;
    }

    for (int i = cur + 1; i < C; i++) {
        path.push_back(v[i]);
        dfs(i);
        path.pop_back();
    }
}

int main() {

    cin >> L >> C;

    for (int i = 0; i < C; i++) {
        char temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    dfs(-1);

    return 0;
}
