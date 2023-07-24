#include <iostream>
using namespace std;

class tree
{
    public:
        struct node
        {
            node *lptr = NULL;
            node *rptr = NULL;
            int data;
        };

        node *root = NULL;
        void inorder(node *ptr)
        {
                if (ptr == NULL)
                {
                    return;
                }
                else
                {
                    inorder(ptr->lptr);
                    cout << ptr->data << " -> ";
                    inorder(ptr->rptr);
                }
            }
        
            void preorder(node *ptr)
            {
                if (ptr == NULL)
                {
                    return;
                }
                else
                {
                    cout << ptr->data << " -> ";
                    preorder(ptr->lptr);
                    preorder(ptr->rptr);
                }
            }
        
            void postorder(node *ptr)
            {
                if (ptr == NULL)
                {
                    return;
                }
                else
                {
                    postorder(ptr->lptr);
                    postorder(ptr->rptr);
                    cout << ptr->data << " -> ";
                }
            }
            
};

int main()
{
    tree t;
    tree::node *root = new tree::node;
    root->data = 2;
    root->lptr = new tree::node;
    root->rptr = new tree::node;
    root->lptr->data = 1;
    root->rptr->data = 8;
    
    
    
    root->lptr=new tree::node;
    root->rptr=new tree::node;
    root->lptr->lptr=new tree::node;
    root->lptr->rptr=new tree::node;
    root->rptr->rptr=new tree::node;
    root->lptr->rptr->lptr=new tree::node;
    root->lptr->rptr->rptr=new tree::node;
    root->rptr->rptr->lptr=new tree::node;
    
    root->data=8;
    root->lptr->data=3;
    root->rptr->data=10;
    root->lptr->lptr->data=1;
    root->lptr->rptr->data=6;
    root->rptr->rptr->data=14;
    root->lptr->rptr->lptr->data=4;
    root->lptr->rptr->rptr->data=7;
    root->rptr->rptr->lptr->data=13;

    t.inorder(root);
    cout << endl;
    t.preorder(root);
    cout << endl;
    t.postorder(root);

    return 0;
}

