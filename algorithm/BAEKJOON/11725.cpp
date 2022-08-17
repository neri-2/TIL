#include <iostream>
#include <vector>

// #11725 Ʈ���� �θ� ã��

using namespace std;

const int MAX = 100000 + 1;

bool visited[MAX] = { 0, }; // �湮 Ȯ��
int parent[MAX]; // ���� ����
vector<int> v[MAX]; // Ʈ�� ����

void dfs(int n) {
	visited[n] = true; // n �湮
	for (int i = 0; i < v[n].size(); i++) { // ����� ���� ��ŭ
		int next = v[n][i]; // Ʈ���� �ڽ� ��� Ȯ��
			if (!visited[next]) {
				parent[next] = n; // �θ��忡�� �̵��ϱ� ����
				dfs(next);
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		// a�� b ����
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1); // 1���� ����
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}
	return 0;
}

// ����: https://jaimemin.tistory.com/585