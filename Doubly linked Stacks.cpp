#include <iostream>
using namespace std;

struct node
{
    int data;
    node *prev;
    node *next;
};

node *top;

void insert()
{
    if (top == NULL)
    {
        top = new node;
        top->prev = NULL;
        top->next = NULL;
        cin >> top->data;
    }
    else if (top != NULL)
    {
        node *q = new node;
        q->prev=NULL;
        top->prev=q;
        q->next=top;
        top=q;
        cin >> q->data;
    }
}

void delete_element()
{
    
}

void forward_display()
{
    node *q = top;
    while (q != NULL)
    {
        cout << q->data << " -> ";
        q = q->next;
    }
}

void backward_display()
{
    node *q, *last;
    q = top;
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


