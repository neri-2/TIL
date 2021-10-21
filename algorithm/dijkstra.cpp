#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define INF 99999999

using namespace std;

vector<vector<pair<int, int>>> graph; // first ���� ���, second ���� ���
vector<int> value;
vector<bool> check;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int N, M;
int ST, EN;

void dijk(int node) {
	
	check[node] = true;

	for (int i = 0; i < graph[node].size(); i++) { //���� ��忡 ����ִ� ���� �� ��ŭ �ݺ�
		if (value[node] + graph[node][i].second < value[graph[node][i].first]) { //(���� ��� �� + ���� �������� ������ ��)�� (���� ����� ��) ��
			value[graph[node][i].first] = value[node] + graph[node][i].second; // �۴ٸ� �� ����
			pq.push({value[graph[node][i].first], graph[node][i].first}); // ���, ���� ��� ���
		}
	}
	while(!pq.empty()) {
		if (!check[pq.top().second]) { //�������� ���� �������
			int next;
			next = pq.top().second; //���� ��� ���� ���� ���� ���� ��� 
			pq.pop(); //�� pop
			dijk(next);
		}
		else
			pq.pop(); //�ߺ��� ��� pop
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	
	for (int i = 0; i <= N; i++) { //�ʱ�ȭ
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
	
	value[ST] = 0; //���� ��� ��� = 0
	dijk(ST);
	
	cout << value[EN] << '\n';
	return 0;
}