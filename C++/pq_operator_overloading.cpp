//
//  priority queue.cpp
//  mincoding_xcode
//
//  Created by chaehee on 2023/08/07.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Pending {
    int priority;
    int idx;

    bool operator<(const Pending right) const {
        if (priority < right.priority) return false;
        else if (priority > right.priority) return true;
        return false;
    }
};

struct Request {
    int start;
    int time;
    int priority;

    bool operator<(const Request right) const {
        if (start > right.start) return false;
        else if (start < right.start) return true;
        return false;
    }
};

int main() {

    int N;
    cin >> N;

    vector<Request> requests;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        requests.push_back({ a,b,i });
    }

    sort(requests.begin(), requests.end());

    int answer = 0;

    priority_queue<Pending> pq;
    int idx = 0, cur_finish = 0, check = 0;
    while (idx < N) {
        cur_finish = requests[idx].start + requests[idx].time;
        check = cur_finish;
        idx++;
        while (idx<N && cur_finish>requests[idx].start) {
            pq.push({ requests[idx].priority, idx });
            cur_finish += requests[idx].time;
            idx++;
        }
        while (!pq.empty()) {
            int nxt_idx = pq.top().idx;
            pq.pop();
            if (answer < check - requests[nxt_idx].start) {
                answer = check - requests[nxt_idx].start;
            }
            check += requests[nxt_idx].time;
        }
    }

    cout << answer;

    return 0;
}