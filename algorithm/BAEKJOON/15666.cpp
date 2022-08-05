#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
vector<int> v;
int N, M;

void seq(int num) {
	v.push_back(arr[num]);
	if (v.size() == M) {
		for (auto o : v)
			cout << o << ' ';
		cout << '\n';
		return;
	}
	for (int i = num; i < N; i++) {
		if (i > 0 && arr[i] == arr[i - 1])
			continue;
		seq(i);
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < N; i++) {
		if (i > 0 && arr[i] == arr[i - 1])
			continue;
		seq(i);
		v.clear();
	}
	return 0;
}