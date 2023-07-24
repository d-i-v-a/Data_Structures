#include <iostream>

using namespace std; //linked stacks

struct node
{
    int data;
    node* link;
};

node* top=NULL;

void push(int value)
{
    node* q;
    q=new node;
    q->data=value;
    q->link=NULL; //how to make a new node syntax
    
    q->link=top;
    top=q;
}
void pop()
{
    if (top == NULL)
    {
        cout << "Underflow";
        return;
    }
    else
    {
        node* q=top;
        top=top->link;
        q->link=NULL;
        delete q;
    }
}
void display()
{
    node* q;
    q=top;
    while (q!=NULL)
    {
        cout << q->data<<" -> ";
        q=q->link;
    }
}

int main()
{
    int y=1;
    while(y==1)
    {
        int ch;
        cout<<"\n1.Push\n2.Pop\n3.Display\n4.Exit\n";
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                int x;
                cout<<"Enter number to be pushed: ";
                cin>>x;
                push(x);
                break;
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                cout<<"Exiting!";
                break;
                return 0;
            }
        }
    }
    return 0;
}



