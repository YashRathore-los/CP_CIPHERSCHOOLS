#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define sort(a) sort(a.begin(),a.end())
#define endl '\n'
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
using namespace std;

class Node {
public:
	int data;
	Node * left;
	Node * right;
	Node(int data) {
		this->data = data;
		this->left = this->right = NULL;
	}
	Node() {
		Node(0);
	}

};

void preorder(Node *root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(Node *root) {
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void postorder(Node *root) {
	if (root == NULL) {
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

int height(Node *root) {
	if (root == NULL) {
		return 0;
	}
	else {
		return 1 + max(height(root->left), height(root->right));
	}
}

void printlevelorder(Node * root, int h) {
	if (root == NULL) {
		return;
	}
	if (h == 1) {
		cout << root->data << " ";
	}
	else if (h > 1) {
		printlevelorder(root->left, h - 1);
		printlevelorder(root->right, h - 1);
	}
}

void levelorder(Node *root) {
	if (root == NULL) {
		return;
	}
	int h = height(root);
	for (int i = 1; i <= h; i++) {
		printlevelorder(root, i);
	}

}

int32_t main() {
#ifndef ONLINE_JUDGE
	/* code */
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	preorder(root);
	cout << endl;
	inorder(root);
	cout << endl;
	postorder(root);
	cout << endl;
	levelorder(root);


}