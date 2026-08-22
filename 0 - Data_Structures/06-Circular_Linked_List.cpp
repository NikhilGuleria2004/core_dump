#include<iostream>
#include<stdexcept>

using namespace std;

class CircularLinkedList{
  private:
  struct Node{
      int data;
      Node* next;
      
      Node(int value): data(value), next(nullptr){}
      
  };
  
  Node* head;
  Node* tail;
  int length;
  
  public:
    CircularLinkedList(): head(nullptr), tail(nullptr), length(0){}
    ~CircularLinkedList(){
        clear();
        }
  
    bool empty()const{
        return head == nullptr;
        }
    int size()const{
        return length;
    }
    
    void push_front(int value){
        Node* node = new Node(value);
        
        if(empty()){
            head = tail = node;
            node->next = head;
        }else{
            node->next = head;
            head = node;
            tail->next = head;
        }
        
        length++;
    }
    
    void push_back(int value){
        Node* node = new Node(value);
        if(empty()){
            head = tail = node;
            node->next = head;
        }
        else{
            tail->next = node;
            tail = node;
            tail->next = head;
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
        
        Node* prev = head;
        
        for(int i=0;i<index-1;  i++) prev = prev->next;
        
        Node* node = new Node(value);
        node->next = prev-> next;
        prev->next= node;
        
        length++;
    }
    
    bool pop_front(){
        if(empty()) return false;
        
        if(head == tail){
            delete head;
            head = tail = nullptr;
            length = 0;
            return true;
        }
        
        Node* temp =  head;
        head = head->next;
        tail->next = head;
        
        delete temp;
        length--;
        return true;
    }
    
    bool pop_back(){
        if(empty()) return false;
        
        if(head ==  tail){
            delete head;
            head = tail = nullptr;
            length = 0;
            return true;
        }
        
        Node* prev = head;
        while(prev->next!=tail)  prev=prev->next;
        
        delete tail;
        tail = prev;
        tail->next =  head;
        
        length--;
        return true;
    }
    
    bool removes(int value){
        if (empty()) return false;
        
        if(head->data == value) return pop_front();
        
        Node* current = head;
        while(current->next != head && current->next->data!=value)
            current = current->next;
            
        if(current->next  == head) return false;
        
        Node* temp= current->next;
        current->next = temp->next;
        if(temp == tail) tail = current;
        
        tail->next = head;
        
        delete temp;
        length--;
        
        return true;
    }
    
    bool contains(int value)const{
        if(empty())  return false;
        
        Node*  current  = head;
        
        do{
            if(current->data == value) return true;
            current = current->next;
        }while(current!=head);
        
        return false;
    }
    
    int indexOf(int value)const{
        if(empty()) return -1;
        
        Node* current = head;
        int index = 0;
        
        do{
            if(current->data == value) return index;
            current = current->next;
            index++;
        }while(current!=head);
        return -1;
    }
    
    int front() const{
        if(empty()) throw runtime_error("List is Empty");
        
        return head->data;
    }
    
    int back() const{
        if(empty()) throw runtime_error("List is empty");
        
        return tail->data;
    }
    
    int at(int index) const{
        if(index<0 || index>=length)
            throw out_of_range("Invalid Index");
            
        Node* current = head;
        
        while(index--) current =  current->next;
        
        return current->data;
    }
    
    void clear(){
        while(!empty()) pop_front();
    }
    
    void display() const{
        if(empty()){
            cout<<"[]\n";
            return;
        }
        
        Node* current = head;
        
        cout<<"[";
        do{
            cout<<current->data;
            current =  current->next;
            
            if(current!=head) cout<<" -> ";
            
        }while(current!=head);
        
        cout<<"](Circular)\n";
    }
  
};

int main() {

    CircularLinkedList list;

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

    list.clear();

    cout << "Size = " << list.size() << endl;

    return 0;
}
