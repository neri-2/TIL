#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// #2108 통계학

bool desc(int a, int b) {
	return a > b;
}

void avg(vector<int> arr, int n) {
	int sum = 0;
	for (auto o : arr) {
		sum += o; // 수 합산
	}
	if (sum >= 0) { // 합이 양수
		if (((double)sum / n) - (sum / n) < 0.5) // 소숫점 자리가 0.5가 넘지 않으면
			cout << sum / n << '\n'; // 내림
		else
			cout << (sum / n) + 1 << '\n'; // 올림
	}
	else { // 합이 음수
		if ((sum / n) - ((double)sum / n) < 0.5) // 음수 버전 
			cout << sum / n << '\n';
		else
			cout << (sum / n) - 1 << '\n'; // 음수기 때문에 -1
	}
}

void median(vector<int> arr, int n) {
	sort(arr.begin(), arr.end()); // 크기 순 정렬
	cout << arr[n / 2] << '\n'; // 배열의 중간에 있는 수 출력
}

void mode(int* m, int n) {
	int result = 0;
	int arr[8001]; // 카운트 체크 배열
	copy(m, m + 8001, arr);
	sort(arr, arr + 8001, desc); // 크기 순 정렬
	if (arr[0] == arr[1]) { // 여러개 있는지 확인
		bool check = false;
		for (int i = 0; i < 8001; i++) { // 가장 작은 수 넘김
			if (!check && m[i] == arr[0]) { // 해당 수의 나온 횟수가 최댓값과 같으면
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
	sort(arr.begin(), arr.end()); // 크기 순 정렬
	cout << arr[n - 1] - arr[0] << '\n'; // 배열 마지막 수 - 배열 첫번째 수
}

int main() {
	int N;
	int m[8001] = { 0, };
	vector<int> arr; // 입력된 수 저장
	cin >> N; // 수의 개수 입력

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
		m[num + 4000]++; // 배열 인덱스를 입력받은 수로 하여 해당 배열의 값을 카운트로 이용
	}

	avg(arr, N);
	median(arr, N);
	mode(m, N);
	range(arr, N);
	return 0;
}