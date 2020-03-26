#include<iostream>
using namespace std;

class Queue
{
private:
    int size;
    int front;
    int rear;
    int* Q;
public:
    Queue(int size){front = rear = 0; this->size = size; Q = new int[this->size];}
    
    void enqueue(int x);
    int dequeue();
    void display();
};
void Queue::enqueue(int x)
{
    if((rear+1)%size == front)
        cout<<"Queue is full\n";
    else
    {
        rear = (rear+1)%size;
        Q[rear] = x;
    }
}
int Queue::dequeue()
{
    int x=0;
    if(front == rear)
        cout<<"Queue is empty\n";
    else
    {
        front = (front+1)%size;
        x = Q[front];
    }
    return x;
}
void Queue::display()
{
    for(int i=front+1; i<=rear; i++)
        cout<<Q[i]<<" | ";
    cout<<endl;
}

int main()
{
    Queue q(10);
    q.enqueue(11);
    q.enqueue(22);
    q.enqueue(33);
    q.enqueue(44);
    
    q.display();
    cout<<endl;
    
    q.dequeue();
    q.dequeue();
    
    q.display();
}
