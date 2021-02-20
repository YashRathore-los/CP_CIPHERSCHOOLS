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
	Node*right;
	Node(int data) {
		this->data = data;
		this->right = this->left = NULL;
	}
	Node() {
		Node(0);
	}
};

void leftview(Node *root) {
	if (root == NULL) {
		return;
	}
	queue<Node*>q;
	q.push(root);
	while (!q.empty()) {
		for (int i = 1; i <= q.size(); i++) {
			Node* tmp = q.front();
			q.pop();
			if (i == 1)
				cout << tmp->data << " ";

			if (tmp->left) {
				q.push(tmp->left);
			}
			if (tmp->right) {
				q.push(tmp->right);
			}
		}
	}
}

int findBottomLeftValue(TreeNode* root) {
	int res = -1, curLevel = 0;
	queue< pair<TreeNode*, int> > q; // node, level
	q.push( { root, 0 } );
	while (!q.empty()) {
		auto [node, level] = q.front();
		q.pop();

		if (curLevel <= level) {
			res = node->val;
			curLevel++;
		}
		if (node->left)
			q.push( { node->left, level + 1 } );
		if (node->right)
			q.push( { node->right, level + 1 } );
	}
	return res;
}

void topView(Node * root) {
	queue<pair<int, Node*>> q; q.push(make_pair(0, root));
	map<int, Node*> ans;
	for (auto i = q.front(); !q.empty(); q.pop(), i = q.front()) {
		if (!i.second) continue;
		ans.insert(i);
		q.push(make_pair(i.first + 1, i.second->right));
		q.push(make_pair(i.first - 1, i.second->left));
	}
	for (auto i : ans) cout << i.second->data << " ";
}

int32_t main() {
#ifndef ONLINE_JUDGE
	/* code */
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Node* root = new Node(10);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(7);
	root->left->right = new Node(8);
	root->right->right = new Node(15);
	root->right->left = new Node(12);
	root->right->right->left = new Node(14);
	leftview(root);
}