#include<iostream>
using namespace std;

class DynamicArray{
    private:
    int* data;
    int size;
    int capacity;
    
    void resize(){
        capacity*=2;
        
        int* newData= new int[capacity];
        
        for(int i=0; i<size;i++){
            newData[i] = data[i];
        }
        
        delete[] data;
        data = newData;
    }
    
    public:
    DynamicArray(){
        size=0;
        capacity =0;
        data = new int[capacity];
    }
    
    ~DynamicArray(){
        delete[] data;
    }
    
    void push_back(int value){
        if(size  == capacity) resize();
        
        data[size++] = value;
    }
    
    void pop_back(){
        if(size>0) size--;
    }
    
    int getSize() const {
        return size;
    }
    
    int& operator[](int index){
        return data[index];
    }
    
    void print(){
        for(int i=0;i<size;i++){
            cout<<data[i]<<" ";
        }
        cout<<'\n';
    }
};

int main(){
    DynamicArray arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    
    arr.print();
    arr.pop_back();
    
    arr.print();
    
    cout<<arr[1]<<endl;
}