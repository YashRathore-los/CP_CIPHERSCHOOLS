#include<bits/stdc++.h>
using namespace std;

struct node *reverse (struct node *head, int k);

struct node
{
    int data;
    struct node* next;

    node(int x) {
        data = x;
        next = NULL;
    }

};

void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0 ; i < n ; i++)
        {
            int value;
            cin >> value;
            if (i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        head = reverse(head, k);
        printList(head);
    }

    return (0);
}



struct node *reverse (struct node *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct node * cur = head;
    struct node *last_ptr = NULL;
    struct node *head_ptr = NULL;
    while (cur != NULL)
    {
        struct node* current = cur;
        struct node* next = NULL;
        struct node* prev = NULL;
        int count = 0;

        while (current != NULL && count < k)
        {
            next  = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }
        if (last_ptr != NULL)
            last_ptr->next = prev;
        if (head_ptr == NULL)
            head_ptr = prev;
        last_ptr = cur;
        cur = next;

    }
    return head_ptr;
}