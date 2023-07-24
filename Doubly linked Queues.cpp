#include <iostream>
using namespace std;

struct node
{
    int data;
    node *prev;
    node *next;
};

node *head, *rear;

void insert()
{
    if (head == NULL)
    {
        head = new node;
        rear = head;
        head->prev = NULL;
        head->next = NULL;
        cin >> head->data;
    }
    else if (head != NULL)
    {
        node *q = new node;
        q->prev = rear;
        rear->next = q;
        cin >> q->data;
        q->next = NULL;
        rear = q;
    }
}

void delete_element()
{
    node *q = head;
    if (rear == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }

    if (rear->next == NULL && rear->prev != NULL)
    {
        rear = rear->prev;
        while (q->next != NULL)
        {
            q = q->next;
        }
        rear->next = NULL;
        delete q->next;
        q->next = NULL;
    }
}

void forward_display()
{
    node *q = head;
    while (q != NULL)
    {
        cout << q->data << " -> ";
        q = q->next;
    }
}

void backward_display()
{
    node *q, *last;
    q = head;
    while (q->next != NULL)
    {
        q = q->next;
    }
    last = q;
    while (last != NULL)
    {
        cout << last->data << " -> ";
        last = last->prev;
    }
}

int main()
{
    int ch = 1;
    while (ch != 5)
    {
        cout << "\n1.Add\n2.Delete\n3.Forward display\n4.Backward display\n5.Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter number to be added: ";
            insert();
            break;
        }
        case 2:
        {
            delete_element();
            break;
        }
        case 3:
        {
            forward_display();
            break;
        }
        case 4:
        {
            backward_display();
            break;
        }
        case 5:
        {
            cout << "Exiting!";
            break;
        }
        default:
        {
            cout << "Invalid choice. Try again." << endl;
            break;
        }
        }
    }
    return 0;
}

