#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// #1966 프린터 큐
// 페어 큐와 우선순위 큐 비교하여 구현

struct Q {
	int value;
	int data;
}; // pair로도 될 듯

void q_input(Q* q, int a, int b) {
	q->value = a;
	q->data = b;
}

int main() {
	int num;
	cin >> num; // 테스트 횟수

	for (int i = 0; i < num; i++) {
		int n = 0;
		int N, M;
		int count = 0;
		vector<int> h;
		vector<Q> queue;

		cin >> N >> M; // 첫번째 줄 입력

		for (int j = 0; j < N; j++) {
			Q q;
			int input;
			cin >> input; // 중요도 입력
			q_input(&q, input, j);
			queue.push_back(q); //순서대로 큐 입력
			h.push_back(input); // 중요도 우선순위대로
		}

		sort(h.rbegin(), h.rend()); // 우선순위 정렬

		int j = 0;

		while (!(h[count] == queue[j].value && queue[j].data == M)) { // 큐의 맨 앞에 있는 문서의 중요도가 가장 높고, 그 문서가 찾던 문서일 때

			if (h[count] == queue[j].value && queue[j].data != M) // 큐의 맨 앞에 있는 문서의 중요도가 가장 높고, 그 문서가 찾던 문서일 때
				count++;
			else
				queue.push_back(queue[j]);
			j++;
		}

		cout << ++count << '\n';
	}
	return 0;
}