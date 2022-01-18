#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define INF 99999999

using namespace std;

vector<vector<pair<int, int>>> graph; // first 도착 노드, second 간선 밸류
vector<int> value;
vector<bool> check;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int N, M;
int ST, EN;

void dijk(int node) {
	
	check[node] = true;

	for (int i = 0; i < graph[node].size(); i++) { //현재 노드에 들어있는 간선 수 만큼 반복
		if (value[node] + graph[node][i].second < value[graph[node][i].first]) { //(현재 노드 값 + 다음 노드까지의 간선의 값)과 (다음 노드의 값) 비교
			value[graph[node][i].first] = value[node] + graph[node][i].second; // 작다면 값 갱신
			pq.push({value[graph[node][i].first], graph[node][i].first}); // 밸류, 목적 노드 페어
		}
	}
	while(!pq.empty()) {
		if (!check[pq.top().second]) { //지나가지 않은 노드인지
			int next;
			next = pq.top().second; //간선 밸류 가장 작은 값의 목적 노드 
			pq.pop(); //힙 pop
			dijk(next);
		}
		else
			pq.pop(); //중복일 경우 pop
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	
	for (int i = 0; i <= N; i++) { //초기화
		vector<pair<int, int>> v;
		graph.push_back(v);
		value.push_back(INF);
		check.push_back(0);
	}
	
	for (int i = 0; i < M; i++) {
		pair<int, int> p;
		int u, v, w;
		cin >> u >> v >> w;
		p = make_pair(v, w);
		graph[u].push_back(p);
	}
	
	cin >> ST >> EN;
	
	value[ST] = 0; //시작 노드 밸류 = 0
	dijk(ST);
	
	cout << value[EN] << '\n';
	return 0;
}