#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v[1001];
int visited[1001];
int answer;

vector<int> preorder;
vector<int> postorder;
vector<int> inorder;

void dfs(int node) {
	visited[node] = 1;
	for (int i = 0; i < v[node].size(); i++) {
		if (!visited[v[node][i]] && v[node][i] != -2) {
			preorder.push_back(v[node][i] + 1);
			dfs(v[node][i]);
			postorder.push_back(v[node][i] + 1);
		}
	}
}

void inorder_dfs(int node) {
	for (int i = 0; i < v[node].size(); i++) {
		if (i == 0 ) { //left이면
			if (v[node][i] != -2) { //더 내려갈 곳이 있으면 내려감
				inorder_dfs(v[node][i]);
        inorder.push_back(node+1); //왼쪽을 모두 탐색한 다음 본인 출력
			}
			else { //더 내려갈 곳이 없으면 본인 출력
				inorder.push_back(node+1);
			}
		}
		else { //right이면
			if (v[node][i] != -2) { //더 내려갈 곳이 있으면 내려감
				inorder_dfs(v[node][i]);
			}
		}
	}
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		int from, to, to2;
		cin >> from >> to >> to2;

		from -= 1;
		to -= 1;
		to2 -= 1;

		v[from].push_back(to);
		v[from].push_back(to2);
	}


	inorder_dfs(0);

	preorder.push_back(1);
	dfs(0);
	postorder.push_back(1);

	for (int i = 0; i < inorder.size(); i++) {
		cout << inorder[i] << ' ';
	}

	cout << endl;

	for (int i = 0; i < preorder.size(); i++) {
		cout << preorder[i] << ' ';
	}

	cout << endl;

	for (int i = 0; i < postorder.size(); i++) {
		cout << postorder[i] << ' ';
	}

	return 0;
}