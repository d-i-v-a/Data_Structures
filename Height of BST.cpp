#include <iostream>
using namespace std;

struct node
{
    node *lptr=NULL;
    node *rptr=NULL;
    int data;
}; 
node *root=NULL;

int findheight(node* root)
{
    int left, right;
    if (root==NULL)
    {
        return 0;
    }
    else
    {
        left=findheight(root->lptr);
        right=findheight(root->rptr);
        
        return max(left, right)+1;
    }
}

bool isbalanced(node* root)
{
    int leftside, rightside, diff;
    if (root==NULL)
    {
        return 0;
    }
    else
    {
        leftside=findheight(root->lptr);
        rightside=findheight(root->rptr);
        diff= abs(leftside-rightside);
        
        if((diff<=1) && (isbalanced(root->lptr)) && (isbalanced(root->rptr)))
        {
            return true;
        }
        else {
            return false;
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
    
    int height = findheight(root);
    cout << "Height of the binary tree: " << height << endl;
    
    if (isbalanced(root))
    {
        cout << "Binary tree is balanced\n";
    }
    else
    {
        cout << "Binary tree is not balanced\n";
    }
    return 0;
}

