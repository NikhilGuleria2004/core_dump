#include<iostream>
using namespace std;

class Queue{
    private:
    int arr[100];
    int front, rear;
    
    public:
    Queue(){
        front =0;
        rear = -1;
    }

    bool isEmpty(){
        return front>rear;
    }
    
    bool isFull(){
        return rear == 99;
    }
    
    void enqueue(int value){
        if(isFull()){
            cout<<"Queue Overflow\n";
            return;
        }
        arr[++rear] = value;
    }
    
    void dequeue(){
        if(isEmpty()){
            cout<<"Queue Underflow\n";
            return;
        }
        cout<<"Removed: "<<arr[front]<<endl;
        front++;
    }
    
    int peek(){
        if(isEmpty()){
            cout<<"Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }
    
    void display(){
        if(isEmpty()){
            cout<<"Queue is Empty\n";
            return;
        }
        
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};


int main(){
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();

    cout << "Front element: " << q.peek() << endl;

    q.display();

    return 0;
}