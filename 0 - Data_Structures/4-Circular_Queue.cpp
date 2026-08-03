#include<iostream>
#include<vector>
using namespace std;

class Queue{
    private:
    vector<int> arr;
    int frontIdx;
    int rearIdx;
    int capacity;
    int count;
    
    public:
    Queue(int size){
        capacity=size;
        arr.resize(capacity);
        frontIdx = 0;
        rearIdx = -1;
        count = 0;
    }
    
    void enqueue(int x){
        if(isFull()){
            cout<<"Queue Overflow\n";
            return;
        }
        
        rearIdx  = (rearIdx+1) % capacity;
        arr[rearIdx] = x;
        count++;
    }
    
    void dequeue(){
        if(isEmpty()){
            cout<<"Queue Underflow\n";
            return;
        }
        frontIdx = (frontIdx+1) %  capacity;
        count--;
    }
    int front(){
        if(isEmpty()){
            cout<<"Queue is Empty\n";
            return -1;
        }
        return arr[frontIdx];
    }
    
    int rear(){
        if(isEmpty()){
            cout<<"Queue is Empty\n";
            return -1;
        }
        return arr[rearIdx];
    }
    
    bool isEmpty(){
        return count  ==0;
    }
    
    bool isFull(){
        return count == capacity;
    }
    
    int size(){
        return count;
    }
    
    void display(){
        if(isEmpty()){
            cout<<"Queue is Empty\n";
            return;
        }
        for(int i=0;i<count; i++){
            cout<<arr[(frontIdx+i) % capacity]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    cout << "Front: " << q.front() << endl;
    cout << "Rear : " << q.rear() << endl;

    q.dequeue();

    q.display();
}