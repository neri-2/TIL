#include <iostream>
#include <vector>

// #1991 트리 순회

using namespace std;

vector<vector<char>> tree;

void pre(char c) {
	cout << c;
	if (tree[c - 65][0] != '.')
		pre(tree[c - 65][0]);
	if (tree[c - 65][1] != '.')
		pre(tree[c - 65][1]);
}

void in(char c) {
	if (tree[c - 65][0] != '.')
		in(tree[c - 65][0]);
	cout << c;
	if (tree[c - 65][1] != '.')
		in(tree[c - 65][1]);
}

void post(char c) {
	if (tree[c - 65][0] != '.')
		post(tree[c - 65][0]);
	if (tree[c - 65][1] != '.')
		post(tree[c - 65][1]);
	cout << c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<char> tmp(2);
		tree.push_back(tmp);
	}

	for (int i = 0; i < n; i++) {
		char parent, left, right;
		cin >> parent >> left >> right;
		tree[parent - 65][0] = left;
		tree[parent - 65][1] = right;
	}

	pre('A');
	cout << '\n';
	in('A');
	cout << '\n';
	post('A');
	cout << '\n';
	return 0;
}