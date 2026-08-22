#include<iostream>
#include<stdexcept>
using namespace std;

class DoublyLinkedList{
    private:
    struct Node{
        int data;
        Node* next;
        Node* prev;
        
        Node(int value)
            :data(value), next(nullptr), prev(nullptr){}
            
    };
    
    Node* head;
    Node* tail;
    int length;
    
    public:
    DoublyLinkedList()
        :head(nullptr), tail(nullptr), length(0){}
    ~DoublyLinkedList(){
        clear();
    }
    
    bool empty()const{
        return head == nullptr;
    }
    
    int size() const{
        return length;
    }
    
    void push_front(int value){
        Node* node = new Node(value);
        node->next= head;
        
        if(head!=nullptr)
            head->prev=node;
        else
            tail=node;
            
        head = node;
        length++;
    }
    
    void push_back(int value){
        Node* node = new Node(value);
        node->prev = tail;
        if(tail!=nullptr) tail->next = node;
        else head =  node;
        
        tail = node;
        length++;
    }
    
    void insertAt(int index, int value){
        if(index<0 || index>length)
            throw out_of_range("Invalid Index");
        
        if(index == 0){
            push_front(value);
            return;
        }
        if(index==length){
            push_back(value);
            return;
        }
        
        Node* current = head;
        
        for(int i=0;  i<index;i++){
            current = current->next;
        }
        
        Node* node = new Node(value);
        node->prev = current->prev;
        node->next = current;
        
        current->prev->next = node;
        current->prev = node;
        
        length++;
    }
    
    bool pop_front(){
        if(empty()) return false;
        
        Node* temp = head;
        head = head->next;
        if(head!=nullptr) head->prev = nullptr;
        else tail=nullptr;
        
        delete temp;
        
        length--;
        return true;
    }
    
    bool pop_back(){
        if(empty()) return false;
        Node* temp = tail;
        tail=tail->prev;
        
        if(tail!=nullptr)tail->next = nullptr;
        else head = nullptr;
        
        delete temp;
        length--;
        return true;
    }
    
    bool removes(int value){
        if(empty()) return false;
        Node* current  = head;
        
        while(current && current->data!=value)
            current = current->next;
            
        if(!current) return false;
        if(current==head) return pop_front();
        if(current==tail) return pop_back();
        
        current->prev->next=current->next;
        current->next->prev=current->prev;
        
        delete current;
        length--;
        return true;
    }
    
    bool contains(int value)const{
        Node* current=head;
        while(current){
            if(current->data==value) return true;
            
            current = current->next;
        }
        return false;
    }
    
    int indexOf(int value)const{
        Node* current = head;
        int index = 0;
        
        while(current){
            if(current->data == value) return index;
            current = current->next;
            index++;
        }
        return -1;
    }
    
    int front() const{
        if(empty()) throw runtime_error("List is Empty");
        
        return head->data;
    }
    
    int back()const{
        if(empty()) throw runtime_error("List is Empty");
        return tail->data;
    }
    
    int at(int index)const{
        if(index<0 || index>=length) throw out_of_range("Invalid Index");
        
        Node* current;
        
        if(index<length/2){
            current = head;
            for(int i=0;i<index;i++) current = current->next;
        }
        else{
            current = tail;
            for(int i=length-1; i>index; i--) current = current->prev;
        }
        return current->data;
    }
    
    void clear(){
        while(head){
            Node* temp = head;
            head  = head->next;
            delete temp;
        }
        
        tail=nullptr;
        length=0;
    }
    
    void display() const{
        Node* current = head;
        cout<<"[";
        while(current){
            cout<<current->data;
            if(current->next) cout<<"<->";
            current=current->next;
        }
        cout<<"]\n";
        
    }
    
    void displayReverse()const{
        Node* current=tail;
        cout<<"[";
        while(current){
            cout<<current->data;
            if(current->prev)cout<<"<->";
            current=current->prev;
        }
        cout<<"]\n";
    }
};

int main() {

    DoublyLinkedList list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    list.push_front(5);

    list.insertAt(2, 15);

    list.display();

    list.removes(20);

    list.display();

    cout << list.front() << endl;
    cout << list.back() << endl;
    cout << list.at(2) << endl;

    cout << list.contains(15) << endl;
    cout << list.indexOf(30) << endl;

    list.pop_front();
    list.pop_back();

    list.display();

    list.displayReverse();

    list.clear();

    cout << "Size = " << list.size() << endl;

    return 0;
}
