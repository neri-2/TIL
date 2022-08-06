#include <iostream>
#include <vector>

// #5639 ���� �˻� Ʈ��

using namespace std;

struct Node { // ��� ����ü
	Node* left;
	Node* right;
	int data;
};

struct Tree { // Ʈ�� ����ü
	Node* root;
};

void initTree(Tree* t) { // Ʈ�� �ʱ�ȭ
	t->root = NULL;
}

Node* createNode(int num) { // ��� ����
	Node* temp = new Node();
	temp->data = num;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void insert(Node* check, int num) { // ���� Ʈ�� �Է�
	if (check->data > num) { // �Էµ� ���� ���� ��� ������ ũ��
		if (check->left == NULL) // ��� �ִٸ�
			check->left = createNode(num); // ���� ����Ʈ�� ����
		else {
			insert(check->left, num); // ���� ����Ʈ�� �̵�
		}
	}
	else if (check->data < num) { // ���� ����
		if (check->right == NULL)
			check->right = createNode(num);
		else {
			insert(check->right, num);
		}
	}
}

void postOrder(Node* n) { // ���� ��ȸ
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
	while (!cin.eof()) { // eof �̿� �Է� ����
		int num;
		cin >> num;
		if (t->root == NULL) { // Ʈ�� ����ִٸ�
			t->root = createNode(num); // ��Ʈ ����
		}
		else {
			insert(t->root, num); // Ʈ�� ����
		}
	}
	postOrder(t->root);
	return 0;
}