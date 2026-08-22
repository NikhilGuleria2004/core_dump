#include<iostream>
using namespace std;

class Deque{
    private:
    int*arr;
    int capacity;
    int front;
    int rear;
    int size;
    
    public:
    Deque(int capacity){
        this->capacity=capacity;
        arr = new int[capacity];
        
        front = 0;
        rear = -1;
        size = 0;
    }
    ~Deque(){
        delete[] arr;
    }
    bool isEmpty(){
        return size==0;
    }
    bool isFull(){
        return size==capacity;
    }
    void pushBack(int value){
        if(isFull()){
            cout<<"Deque is full\n";
            return;
        }
        rear = (rear+1)%capacity;
        arr[rear]=value;
        size++;
    }
    
    void pushFront(int value){
        if(isFull()){
            cout<<"Deque is full\n";
            return;
        }
        front = (front-1+capacity)%capacity;
        arr[front] = value;
        size++;
    }
    
    void popFront(){
        if(isEmpty()){
            cout<<"Deque is Empty\n";
            return;
        }
        front=(front+1)%capacity;
        size--;
    }
    
    void popBack(){
        if(isEmpty()){
            cout<<"Deque is Empty\n";
            return;
        }
        rear = (rear-1+capacity)%capacity;
        size--;
    }
    
    int getFront(){
        if(isEmpty()){
            cout<<"Deque is Empty\n";
            return -1;
        }
        return arr[front];
    }
    
    int getBack(){
        if(isEmpty()){
            cout<<"Deque is Empty\n";
            return -1;
        }
        return arr[rear];
    }
};

int main() {
    Deque d(5);

    d.pushBack(10);
    d.pushBack(20);
    d.pushBack(30);

    d.pushFront(5);

    cout << d.getFront() << '\n'; // 5
    cout << d.getBack() << '\n';  // 30

    d.popFront();

    cout << d.getFront() << '\n'; // 10

    d.popBack();

    cout << d.getBack() << '\n';  // 20
}
