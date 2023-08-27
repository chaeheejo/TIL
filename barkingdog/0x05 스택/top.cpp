//
//  top.cpp
//  algorithm
//
//  Created by chaehee on 2023/08/15.
//

#include <iostream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

int N;
int result[500000];

int main() {
    
    cin >> N;
    
    vector<int> top;
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        top.push_back(temp);
    }
    
    stack<pair<int, int>> st;
    for (int i = top.size() - 1; i > -1; i--) {
        if (st.empty()) {
            st.push({ top[i],i});
        }
        else {
            if (st.top().first > top[i]) {
                st.push({ top[i],i });
            }
            else{
                while (!st.empty() && st.top().first < top[i]) {
                    int idx = st.top().second;
                    result[idx] = i+1;
                    st.pop();
                }
                st.push({ top[i],i });
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        cout << result[i] << ' ';
    }
    
    return 0;
}
