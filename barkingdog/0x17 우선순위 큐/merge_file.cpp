//
//  merge_file.cpp
//  algorithm
//
//  Created by chaehee on 2023/10/01.
//

#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;

        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (int n = 0; n < N; n++) {
            int temp;
            cin >> temp;
            pq.push(temp);
        }

        ll answer = 0;
        while (pq.size()>1) {
            ll cur = 0;
            for (int i = 0; i < 2; i++) {
                cur += pq.top();
                pq.pop();
            }
            answer += cur;
            pq.push(cur);
        }
        cout << answer << '\n';
    }


    return 0;
}
