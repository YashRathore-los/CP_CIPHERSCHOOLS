bool ispresent(struct node *head, int data)
{
    while (head != NULL)
    {
        if (head->data == data)
            return true;
        head = head->next;
    }
    return false;
}
void union1(struct node *a, struct node *b)
{
    struct node *union1 = NULL;
    struct node *head1 = a;
    while (a)
    {
        push(&union1, a->data);
        a = a->next;
    }
    while (b)
    {
        if (!ispresent(head1, b->data))
            push(&union1, b->data);
        b = b->next;
    }
    printlist(union1);
}
void inter(struct node *a, struct node *b)
{
    struct node *inter = NULL;
    while (a)
    {
        if (ispresent(b, a->data))
            push(&inter, a->data);
        a = a->next;
    }
    printlist(inter);
}

//both lists are sorted

void unionlist(struct node *a, struct node *b)
{
    struct node *union1 = NULL;
    while (a && b)
    {
        if (a->data < b->data)
        {
            push(&union1, a->data);
            a = a->next;
        }
        else if (a->data > b->data)
        {
            push(&union1, b->data);
            b = b->next;
        }
        else
        {
            push(&union1, a->data);
            a = a->next;
            b = b->next;
        }
    }
    while (a)
    {
        push(&union1, a->data);
        a = a->next;
    }
    while (b)
    {
        push(&union1, b->data);
        b = b->next;
    }
    printlist(union1);
}
void interlist(struct node *a, struct node *b)
{
    struct node *inter = NULL;
    while (a && b)
    {
        if (a->data < b->data)
            a = a->next;
        else if (a->data > b->data)
            b = b->next;
        else
        {
            push(&inter, a->data);
            a = a->next;
            b = b->next;
        }
    }
    printlist(inter);
}

void unionhash(struct node *a, struct node *b)
{
    map <int, struct node *> m;
    struct node *union1 = NULL;
    while (a)
    {
        push(&union1, a->data);
        m[a->data] = a;
        a = a->next;
    }
    while (b)
    {
        if (m.find(b->data) == m.end())
            push(&union1, b->data);
        b = b->next;
    }
    printlist(union1);
}

void interhash(struct node *a, struct node *b)
{
    map <int, struct node *> m;
    struct node *inter = NULL;
    while (a)
    {
        m[a->data] = a;
        a = a->next;
    }
    while (b)
    {
        if (m.find(b->data) != m.end())
            push(&inter, b->data);
        b = b->next;
    }
    printlist(inter);
}