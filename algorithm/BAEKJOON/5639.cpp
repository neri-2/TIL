#include <iostream>
#include <vector>

// #5639 이진 검색 트리

using namespace std;

struct Node { // 노드 구조체
	Node* left;
	Node* right;
	int data;
};

struct Tree { // 트리 구조체
	Node* root;
};

void initTree(Tree* t) { // 트리 초기화
	t->root = NULL;
}

Node* createNode(int num) { // 노드 생성
	Node* temp = new Node();
	temp->data = num;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void insert(Node* check, int num) { // 이진 트리 입력
	if (check->data > num) { // 입력된 수가 현재 노드 값보다 크면
		if (check->left == NULL) // 비어 있다면
			check->left = createNode(num); // 왼쪽 서브트리 생성
		else {
			insert(check->left, num); // 왼쪽 서브트리 이동
		}
	}
	else if (check->data < num) { // 위와 동일
		if (check->right == NULL)
			check->right = createNode(num);
		else {
			insert(check->right, num);
		}
	}
}

void postOrder(Node* n) { // 후위 순회
	if (!n)
		return;
	postOrder(n->left);
	postOrder(n->right);
	cout << n->data << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Tree* t = new Tree();
	initTree(t);
	while (!cin.eof()) { // eof 이용 입력 종료
		int num;
		cin >> num;
		if (t->root == NULL) { // 트리 비어있다면
			t->root = createNode(num); // 루트 생성
		}
		else {
			insert(t->root, num); // 트리 삽입
		}
	}
	postOrder(t->root);
	return 0;
}