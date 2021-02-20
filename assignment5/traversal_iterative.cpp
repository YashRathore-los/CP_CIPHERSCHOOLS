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
	Node *left;
	Node *right;
	Node(int data) {
		this->data = data;
		this->left = this->right = NULL;
	}
	Node() {
		Node(0);
	}
};

void preorder(Node * root) {
	if (root == NULL) {
		return;
	}
	stack<Node*>s;
	while (1) {
		while (root != NULL) {
			cout << root->data << " ";
			s.push(root);
			root = root->left;
		}
		if (s.empty()) {
			return;
		}
		root = s.top();
		s.pop();
		root = root->right;
	}
}

void inorder(Node * root) {
	if (root == NULL) {
		return;
	}
	stack<Node*>s;
	while (1) {
		while (root != NULL) {
			s.push(root);
			root = root->left;
		}
		if (s.empty()) {
			return;
		}
		root = s.top();
		s.pop();
		cout << root->data << " ";
		root = root->right;
	}
}

void postorder(Node *root) {
	if (root == NULL) {
		return;
	}
	stack<Node*>s1, s2;
	s1.push(root);
	while (!s1.empty()) {
		root = s1.top();
		s1.pop();
		s2.push(root);
		if (root->left != NULL) {
			s1.push(root->left);
		}
		if (root->right != NULL) {
			s1.push(root->right);
		}
	}
	while (!s2.empty()) {
		cout << s2.top()->data << " ";
		s2.pop();
	}
}

void levelorder(Node * root) {
	if (root == NULL) {
		return;
	}
	queue<Node*>q;
	q.push(root);
	while (!q.empty()) {
		Node* tmp = q.front();
		cout << tmp->data << " ";
		q.pop();
		if (tmp->left) {
			q.push(tmp->left);
		}
		if (tmp->right) {
			q.push(tmp->right);
		}
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