#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// #2108 �����

bool desc(int a, int b) {
	return a > b;
}

void avg(vector<int> arr, int n) {
	int sum = 0;
	for (auto o : arr) {
		sum += o; // �� �ջ�
	}
	if (sum >= 0) { // ���� ���
		if (((double)sum / n) - (sum / n) < 0.5) // �Ҽ��� �ڸ��� 0.5�� ���� ������
			cout << sum / n << '\n'; // ����
		else
			cout << (sum / n) + 1 << '\n'; // �ø�
	}
	else { // ���� ����
		if ((sum / n) - ((double)sum / n) < 0.5) // ���� ���� 
			cout << sum / n << '\n';
		else
			cout << (sum / n) - 1 << '\n'; // ������ ������ -1
	}
}

void median(vector<int> arr, int n) {
	sort(arr.begin(), arr.end()); // ũ�� �� ����
	cout << arr[n / 2] << '\n'; // �迭�� �߰��� �ִ� �� ���
}

void mode(int* m, int n) {
	int result = 0;
	int arr[8001]; // ī��Ʈ üũ �迭
	copy(m, m + 8001, arr);
	sort(arr, arr + 8001, desc); // ũ�� �� ����
	if (arr[0] == arr[1]) { // ������ �ִ��� Ȯ��
		bool check = false;
		for (int i = 0; i < 8001; i++) { // ���� ���� �� �ѱ�
			if (!check && m[i] == arr[0]) { // �ش� ���� ���� Ƚ���� �ִ񰪰� ������
				check = true;
				result = i - 4000;
				continue;
			}
			if (check && m[i] == arr[0]) {
				result = i - 4000;
				break;
			}
		}
	}
	else {
		for (int i = 0; i < 8001; i++) {
			if (m[i] == arr[0]) {
				result = i - 4000;
				break;
			}
		}
	}
	cout << result << '\n';
}

void range(vector<int> arr, int n) {
	sort(arr.begin(), arr.end()); // ũ�� �� ����
	cout << arr[n - 1] - arr[0] << '\n'; // �迭 ������ �� - �迭 ù��° ��
}

int main() {
	int N;
	int m[8001] = { 0, };
	vector<int> arr; // �Էµ� �� ����
	cin >> N; // ���� ���� �Է�

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
		m[num + 4000]++; // �迭 �ε����� �Է¹��� ���� �Ͽ� �ش� �迭�� ���� ī��Ʈ�� �̿�
	}

	avg(arr, N);
	median(arr, N);
	mode(m, N);
	range(arr, N);
	return 0;
}