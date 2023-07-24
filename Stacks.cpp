#include <iostream>

using namespace std;

class stack
{
    private: 
        int top=-1;
        static const int maxstack=10;
        int s[maxstack];
        
    public:
        void push(int num)
        {
            if (top==maxstack)
            {
                cout<<"STACK OVERFLOW!";
            }
            else
            {
                top+=1;
                s[top]=num;
            }
        }
        void pop()
        {
            if(top<0)
            {
                cout<< "STACK UNDERFLOW";
            }
            else
            {
                cout<< "Element popped: "<< s[top];
                top--;
            }
        }
        void display()
        {
            for (int i=top; i>=0; i--)
            {
                cout<<s[i];
            }
        }
};

int main()
{
    int y=1;
    stack st;
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
                st.push(x);
                break;
             case 2:
                st.pop();
                break;
             case 3:
                st.display();
                break;
             case 4:
                cout<<"Exiting!";
                break;
        }
    }

    return 0;
}
