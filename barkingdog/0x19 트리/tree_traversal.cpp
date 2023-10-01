//
//  tree_traversal.cpp
//  algorithm
//
//  Created by chaehee on 2023/10/01.
//

#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> graph[26];
int visited[26];

vector<char> preorder;
vector<char> postorder;
vector<char> inorder;

void dfs(int node) {
    visited[node] = 1;
    for (int i = 0; i < graph[node].size(); i++) {
        if (!visited[graph[node][i]] && graph[node][i] != -1) {
            preorder.push_back(graph[node][i] +'A');
            dfs(graph[node][i]);
            postorder.push_back(graph[node][i]+'A');
        }
    }
}

void inorder_dfs(int node) {
    for (int i = 0; i < graph[node].size(); i++) {
        if (i == 0) {
            if (graph[node][i] != -1) {
                inorder_dfs(graph[node][i]);
                inorder.push_back(node + 'A');
            }
            else {
                inorder.push_back(node + 'A');
            }
        }
        else {
            if (graph[node][i] != -1) {
                inorder_dfs(graph[node][i]);
            }
        }
    }
}

int main() {

    cin >> N;

    for (int i = 0; i < N; i++) {
        char a, b, c;
        cin >> a >> b >> c;

        int cur, lchild, rchild;

        cur = a - 'A';
        if (b == '.') {
            lchild = -1;
        }
        else {
            lchild = b - 'A';
        }

        if (c == '.') {
            rchild = -1;
        }
        else {
            rchild = c - 'A';
        }

        graph[cur].push_back(lchild);
        graph[cur].push_back(rchild);
    }

    inorder_dfs(0);
    preorder.push_back('A');
    dfs(0);
    postorder.push_back('A');

    for (int i = 0; i < preorder.size(); i++) {
        cout << preorder[i];
    }
    cout << '\n';

    for (int i = 0; i < inorder.size(); i++) {
        cout << inorder[i];
    }
    cout << '\n';

    for (int i = 0; i < postorder.size(); i++) {
        cout << postorder[i];
    }

    return 0;
}
