#include <iostream>

using namespace std;

class Queue 
{
    private:
        static const int maxq = 10;
        int q[maxq];
        int front = -1;
        int rear = -1;

    public:
        void enqueue(int value) 
        {
            if (front == -1 && rear == -1) 
            {
                front = rear = 0;
            }
            else if ((rear + 1) % maxq == front) 
            {
                cout << "Queue is Full.";
            }
            else 
            {
                rear = (rear + 1) % maxq;
            }
            q[rear] = value;
        }

        void dequeue() 
        {
            if (front == -1 && rear == -1) 
            {
                cout << "Queue is Empty.\n";
                return;
            }
            else if (front == rear) 
            {
                front = rear = -1;
            }
            else 
            {
                front = (front + 1) % maxq;
            }
        }

        void display() 
        {
            int i = front;
            
            while (i != (rear + 1) % maxq) 
            {
                cout << q[i] << " ";
                i = (i + 1) % maxq;
            }
            cout << endl;
        }
};

int main() 
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();
    
    q.dequeue();
    q.display();
    
    q.dequeue();
    q.display();

    return 0;
}

