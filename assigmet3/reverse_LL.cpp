#include<bits/stdc++.h>
#define MOD 1000000007
#define sort(a) sort(a.begin(),a.end())
#define endl '\n'
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
using namespace std;

struct Node {
	int data;
	struct Node *next;
	Node(int data) {
		this->data = data;
		next = NULL;
	}
};

struct LLNode {
	Node *head;
	LLNode() {
		head = NULL;
	}
	void push(int data) {
		Node*tmp = new Node(data);
		tmp->next = head;
		head = tmp;
	}
};



void print(Node *head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	return;

}
void reverse(Node *head) {
	Node * current = head;
	Node* next = NULL;
	Node* prev = NULL;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
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


	LLNode ll;
	ll.push(5);
	ll.push(4);
	ll.push(3);
	ll.push(2);
	ll.push(1);
	print(head);
	cout << endl;
	reverse(head);
	print(head);

	return 0;
}