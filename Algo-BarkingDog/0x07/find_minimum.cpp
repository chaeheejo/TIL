//
//  find_minimum.cpp
//  algorithm
//
//  Created by chaehee on 2023/08/17.
//

#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int L;
    cin >> L;

    int temp = 0, start = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    for (int n = 0; n < N; n++) {
        cin >> temp;
        pq.push({ temp,n });
        while (n-L+1>=0  && pq.top().second < n-L+1) {
            pq.pop();
        }
        cout << pq.top().first << ' ';
    }

    return 0;
}
