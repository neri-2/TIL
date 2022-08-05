#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<bool> check;
vector<int> arr;
vector<int> v;
int N, M;

void seq(int num) { // ���� ���ϱ� �Լ�
	v.push_back(arr[num]); // num �ε����� �� ������ �Է�
	check[num] = true; // �ش� �ε��� ���� ������ ����ִ���

	if (v.size() == M) { // ������ ũ�Ⱑ ������ ���̿� ���ٸ�
		for (auto o : v)
			cout << o << ' '; // ���
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++) {
		if (i > 0 && !check[i - 1] && arr[i] == arr[i - 1]) // �ߺ��Ǵ� ������ �ƴ��� Ȯ���ϱ�
			// i - 1�� ������ �� ���� �ƴϰ� i - 1 �ε����� i �ε����� ���� ������
			continue;
		if (!check[i]) { // i �ε����� ���� ������ ������� �ʴٸ�
			seq(i); // ������ �� ���� �� �� ���ϱ�
			v.pop_back(); // ���� �� �� ���ϱ� ���� �ʱ�ȭ
			check[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M; // �Է�

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num; // �� �Է�
		arr.push_back(num); // �� �迭
		check.push_back(0); // Ȯ�� �迭
	}
	sort(arr.begin(), arr.end()); // �� �������� ����

	for (int i = 0; i < N; i++) {
		if (i > 0 && arr[i] == arr[i - 1])
			continue;
		seq(i); // i �ε��� ���� �����ϴ� ���� ����
		v.clear(); // ���� ���� �ʱ�ȭ
		check[i] = false;
	}
	return 0;
}