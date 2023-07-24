#include <iostream>

using namespace std;

struct node
{
    node *lptr=NULL;
    node *rptr=NULL;
    int data;
}; 

node *root=NULL;

void inorder(node *ptr)
{
    if (ptr==NULL)
    {
        return;
    }
    else
    {
        inorder(ptr->lptr);
        cout << ptr->data <<" -> ";
        inorder(ptr->rptr);
    }
    
}

void preorder(node *ptr)
{
    if (ptr==NULL)
    {
        return;
    }
    else
    {
        cout<<ptr->data<<" -> ";
        preorder(ptr->lptr);
        preorder(ptr->rptr);
    }
}

void postorder(node *ptr)
{
    if (ptr==NULL)
    {
        return;
    }
    else
    {
        postorder(ptr->lptr);
        postorder(ptr->rptr);
        cout<<ptr->data<<" -> ";
    }
}
int search(int key, node *ptr)
{
    if (ptr==NULL)
    {
        return 0;
    }
    else if (ptr->data==key)
    {
        return 1;
    }
    else
    {
        if(key<ptr->data)
        {
            search(key, ptr->lptr);
        }
        else if(key>ptr->data)
        {
            search(key, ptr->rptr);
        }
    }
}

int main()
{
    root=new node;
    root->lptr=new node;
    root->rptr=new node;
    root->lptr->lptr=new node;
    root->lptr->rptr=new node;
    root->rptr->rptr=new node;
    root->lptr->rptr->lptr=new node;
    root->lptr->rptr->rptr=new node;
    root->rptr->rptr->lptr=new node;
    
    root->data=8;
    root->lptr->data=3;
    root->rptr->data=10;
    root->lptr->lptr->data=1;
    root->lptr->rptr->data=6;
    root->rptr->rptr->data=14;
    root->lptr->rptr->lptr->data=4;
    root->lptr->rptr->rptr->data=7;
    root->rptr->rptr->lptr->data=13;
    
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    
    int x=search(0, root);
    if (x==1)
    {
        cout<<"\nFound!!";
    }
    else
    {
        cout<<"\nNOT FOUND";
    }
    
    return 0;
}


