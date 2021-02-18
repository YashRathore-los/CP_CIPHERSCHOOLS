#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};


Node* newNode(int data)
{
	Node* new_node = new Node();
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}


void push(Node** head_ref, int new_data)
{
	Node* new_node = newNode(new_data);

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

Node* addTwoLists(Node* first, Node* second)
{

	Node* res = NULL;
	Node *temp, *prev = NULL;
	int carry = 0, sum;


	while (first != NULL
	        || second != NULL) {

		sum = carry + (first ? first->data : 0)
		      + (second ? second->data : 0);

		carry = (sum >= 10) ? 1 : 0;

		sum = sum % 10;

		temp = newNode(sum);


		if (res == NULL)
			res = temp;


		else
			prev->next = temp;

		prev = temp;


		if (first)
			first = first->next;
		if (second)
			second = second->next;
	}

	if (carry > 0)
		temp->next = newNode(carry);

	return res;
}

// A utility function to print a linked list
void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
	cout << endl;
}

/* Driver code */
int main(void)
{
#ifndef ONLINE_JUDGE
	/* code */
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Node* res = NULL;
	Node* first = NULL;
	Node* second = NULL;

	// create first list 7->5->9->4->6
	push(&first, 6);
	push(&first, 4);
	push(&first, 9);
	push(&first, 5);
	push(&first, 7);
	printf("First List is ");
	printList(first);

	// create second list 8->4
	push(&second, 4);
	push(&second, 8);
	cout << "Second List is ";
	printList(second);

	// Add the two lists and see result
	res = addTwoLists(first, second);
	cout << "Resultant list is ";
	printList(res);

	return 0;
}