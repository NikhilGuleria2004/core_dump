#include<iostream>
#include<stdexcept>

using namespace std;

class SinglyLinkedList{
    private:
    struct Node{
        int data;
        Node* next;
        
        Node(int value) :  data(value), next(nullptr){}
    };
    
    Node* head;
    Node* tail;
    int length;
    
    public:
    SinglyLinkedList()
        :head(nullptr), tail(nullptr),  length(0){}
    
    ~SinglyLinkedList(){
        clear();
    }
    
    bool empty() const{
        return head == nullptr;
    }
    int size() const{
        return length;
    }
    
    void push_front(int value){
        Node* node = new Node(value);
        node->next=head;
        
        if(tail==nullptr)
            tail = node;
            
        length++;
    }
    
    void push_back(int value){
        Node* node = new Node(value);
        if(empty()){
            head = tail = node;
        }
        else{
            tail->next = node;
            tail =  node;
        }
        length++;
    }
    
    void insertAt(int index, int value){
        if(index<0 || index>length)
            throw out_of_range("Invalid Index");
        if(index==0){
            push_front(value);
            return;
        }
        if(index==length){
            push_back(value);
            return;
        }
        
        Node* prev=head;
        
        for(int i=0; i<index-1; i++)
            prev = prev->next;
            
        Node* node = new Node(value);
        node->next=prev->next;
        prev->next = node;
        
        length++;
        
    }
    
    bool pop_front(){
        if(empty()) return false;
        
        Node* temp = head;
        head = head->next;
        delete temp;
        
        length--;
        
        if(head == nullptr) tail = nullptr;
        
        return true;
    }
    
    bool pop_back(){
        if(empty()) return false;
        if(head==tail){
            delete head;
            head = tail = nullptr;
            length=0;
            return true;
        }
        
        Node* prev= head;
        while(prev->next != tail) prev=prev->next;
        
        delete tail;
        
        tail=prev;
        tail->next = nullptr;
        
        length--;
        
        return true;
    }
    
    bool removes(int value){
        if(empty()) return false;
        if(head->data==value)return pop_front();
        
        Node* current=head;
        
        while(current->next &&current->next->data!=value)
            current=current->next;
            
        if(!current->next) return false;
        
        Node* temp= current -> next;
        
        current->next = temp->next;
        
        if(temp==tail) tail = current;
        
        delete temp;
        
        length--;
        return true;
    }
    
    bool contains(int value)const{
        Node* current=  head;
        while(current){
            if(current->data==value) return true;
            current= current->next;
        }
        
        return false;
    }
    
    int indexOf(int value) const{
        Node* current = head;
        int index = 0;
        
        while(current){
            if(current->data == value) return index;
            current= current->next;
            index++;
        }
        
        return -1;
    }
    
    
    int front()const{
        if(empty()) throw runtime_error("list is empty");
        return head-> data;
    }
    
    int back() const{
        if(empty()) throw runtime_error("List is Empty");
        return tail->data;
    }
    
    int at(int index) const{
        if(index<0 || index>=length)
            throw out_of_range("Invalid index");
        Node* current =  head;
        while(index--) current = current->next;
        return current->data;
    }
    
    void clear(){
        while(head){
            Node* temp = head;
            head =  head->next;
            delete temp;
        }
        
        tail = nullptr;
        length=0;
    }
    
    void display() const{
        Node* current = head;
        cout<<"[";
        while(current){
            cout<<current->data;
            if(current->next) cout<<" -> ";
            current = current->next;
        }
        cout<<"]\n";
    }
};

int main() {

    SinglyLinkedList list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    list.push_front(5);

    list.insertAt(2, 15);

    list.display();        // [5 -> 10 -> 15 -> 20 -> 30]

    list.removes(20);

    list.display();        // [5 -> 10 -> 15 -> 30]

    cout << list.front() << endl;
    cout << list.back() << endl;
    cout << list.at(2) << endl;

    cout << list.contains(15) << endl;
    cout << list.indexOf(30) << endl;

    list.pop_front();
    list.pop_back();

    list.display();

    list.clear();

    cout << "Size = " << list.size() << endl;
}