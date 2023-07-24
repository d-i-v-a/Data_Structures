#include <iostream>

using namespace std;

struct node
{
    int data;
    node* link;
};
    node* front=NULL;
    node* rear=NULL;
    node* q;
    
void dequeue()
{
    if (front==NULL)
    {
        cout<<"Underflow";
    }
    else
    {
        q=front;
        front=front->link;
        q->link=NULL;
        delete q;
    }
}
void enqueue(int value)
{
    if (front==NULL && rear==NULL)
    {
        node* q=new node;
        q->data=value;
        q->link=NULL;
        front=rear=q;
    }
    else
    {
        node *q=new node;
        q->link=NULL;
        q->data=value;
        rear->link=q;
        rear=rear->link;
    }
    
}
void display()
{
    node* q;
    q=front;
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
        cout<<"\n1.Add\n2.Delete\n3.Display\n4.Exit\n";
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                int x;
                cout<<"Enter number to be added: ";
                cin>>x;
                enqueue(x);
                break;
            case 2:
            {
                dequeue();
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
