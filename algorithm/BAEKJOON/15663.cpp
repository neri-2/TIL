#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<bool> check;
vector<int> arr;
vector<int> v;
int N, M;

void seq(int num) { // 수열 구하기 함수
	v.push_back(arr[num]); // num 인덱스의 수 수열에 입력
	check[num] = true; // 해당 인덱스 수가 수열에 들어있는지

	if (v.size() == M) { // 벡터의 크기가 수열의 길이와 같다면
		for (auto o : v)
			cout << o << ' '; // 출력
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++) {
		if (i > 0 && !check[i - 1] && arr[i] == arr[i - 1]) // 중복되는 수열이 아닌지 확인하기
			// i - 1이 수열에 들어간 수가 아니고 i - 1 인덱스와 i 인덱스의 값이 같으면
			continue;
		if (!check[i]) { // i 인덱스의 수가 수열에 들어있지 않다면
			seq(i); // 수열에 들어갈 다음 번 수 구하기
			v.pop_back(); // 다음 번 수 구하기 위해 초기화
			check[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M; // 입력

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num; // 수 입력
		arr.push_back(num); // 수 배열
		check.push_back(0); // 확인 배열
	}
	sort(arr.begin(), arr.end()); // 수 오름차순 정렬

	for (int i = 0; i < N; i++) {
		if (i > 0 && arr[i] == arr[i - 1])
			continue;
		seq(i); // i 인덱스 수로 시작하는 수열 생성
		v.clear(); // 수열 벡터 초기화
		check[i] = false;
	}
	return 0;
}