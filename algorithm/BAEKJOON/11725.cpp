#include <iostream>
#include <vector>

// #11725 트리의 부모 찾기

using namespace std;

const int MAX = 100000 + 1;

bool visited[MAX] = { 0, }; // 방문 확인
int parent[MAX]; // 정답 저장
vector<int> v[MAX]; // 트리 생성

void dfs(int n) {
	visited[n] = true; // n 방문
	for (int i = 0; i < v[n].size(); i++) { // 연결된 숫자 만큼
		int next = v[n][i]; // 트리의 자식 노드 확인
			if (!visited[next]) {
				parent[next] = n; // 부모노드에서 이동하기 때문
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
		// a와 b 연결
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1); // 1부터 시작
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}
	return 0;
}

// 참고: https://jaimemin.tistory.com/585