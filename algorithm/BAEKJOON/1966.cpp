#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// #1966 ������ ť
// ��� ť�� �켱���� ť ���Ͽ� ����

struct Q {
	int value;
	int data;
}; // pair�ε� �� ��

void q_input(Q* q, int a, int b) {
	q->value = a;
	q->data = b;
}

int main() {
	int num;
	cin >> num; // �׽�Ʈ Ƚ��

	for (int i = 0; i < num; i++) {
		int n = 0;
		int N, M;
		int count = 0;
		vector<int> h;
		vector<Q> queue;

		cin >> N >> M; // ù��° �� �Է�

		for (int j = 0; j < N; j++) {
			Q q;
			int input;
			cin >> input; // �߿䵵 �Է�
			q_input(&q, input, j);
			queue.push_back(q); //������� ť �Է�
			h.push_back(input); // �߿䵵 �켱�������
		}

		sort(h.rbegin(), h.rend()); // �켱���� ����

		int j = 0;

		while (!(h[count] == queue[j].value && queue[j].data == M)) { // ť�� �� �տ� �ִ� ������ �߿䵵�� ���� ����, �� ������ ã�� ������ ��

			if (h[count] == queue[j].value && queue[j].data != M) // ť�� �� �տ� �ִ� ������ �߿䵵�� ���� ����, �� ������ ã�� ������ ��
				count++;
			else
				queue.push_back(queue[j]);
			j++;
		}

		cout << ++count << '\n';
	}
	return 0;
}