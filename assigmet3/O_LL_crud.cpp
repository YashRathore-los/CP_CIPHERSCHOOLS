#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define sort(a) sort(a.begin(),a.end())
#define endl '\n'
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
using namespace std;

struct Node {
	int data;
	struct Node *next;
};

void print(Node *head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	return;

}

void deletNode(Node *head, int pos) {
	if (head == NULL) {
		return;
	}
	struct Node *tmp = head;
	if (pos == 0) {
		head = tmp->next;
		free(tmp);
		return;
	}
	int i = 0;
	while (tmp != NULL && i < pos - 1) {
		tmp = tmp->next;
	}
	if (tmp == NULL || tmp->next) {
		return;
	}
	struct Node* next = tmp->next->next;
	free(tmp->next);
	tmp->next = next;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	/* code */
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	struct Node *head = NULL;
	struct Node *second = NULL;
	struct Node *third = NULL;

	head = new Node;
	second = new Node;
	third = new Node;;
	head->data = 1;
	head->next = second;
	second->data = 2;
	second->next = third;
	third->data = 3;
	third->next = NULL;
	print(head);
	deletNode(head, 2);
	print(head);

	return 0;
}