#include<iostream>
#include<vector>

using namespace std;
class Node{
    public:
    int data;
    Node* next;
    
    Node(int val){
        data = val;
        next = nullptr;
    }
};
class vecStack{
    private:
    vector<int> arr;
    
    public:
    void push(int x){
        arr.push_back(x);
    }
    
    void pop(){
        if(isEmpty()){
            cout<<"Stack Underflow\n";
            return;
        }
        arr.pop_back();
    }
    
    int top(){
        if(isEmpty()){
            cout<<"Stack is Empty\n";
            return -1;
        }
        return arr.back();
    }
    
    bool isEmpty(){
        return arr.empty();
    }
    
    int size(){
        return arr.size();
    }
    
    void display(){
        for(int i=arr.size()-1;i>=0; i--)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
};

class llStack{
  private:
  Node* head;
  int count;
  
  public:
  llStack(){
      head = nullptr;
      count = 0;
  }
  
  void push(int x){
      Node* temp = new Node(x);
      temp->next = head;
      head = temp;
      count++;
  }
  void pop(){
      if(isEmpty()){
          cout<<"Stack Underflow\n";
          return;
      }
      
      Node* temp = head;
      head = head->next;
      delete temp;
      count--;
  }
  
  int top(){
      if(isEmpty()){
          cout<<"Stack is empty\n";
          return -1;
      }
      return head->data;
  }
  
  bool isEmpty(){
      return head == nullptr;
  }
  
  int size(){
      return count;
  }
  
  void display(){
      Node*curr = head;
      while(curr){
          cout<<curr->data<<" ";
          curr = curr->next;
      }
      cout<<endl;
  }
  
  ~llStack(){
      while(!isEmpty())
      pop();
  }
};

int main(){
    vecStack sv;
    sv.push(1);
    sv.push(2);
    sv.push(3);
    sv.push(4);
    sv.push(5);
    
    sv.display();
    cout<<"SV TOP: "<<sv.top()<<endl;
    
    sv.pop();
    sv.display();
    cout<<"LLS"<<endl;
    llStack lls;
    lls.push(6);
    lls.push(7);
    lls.push(8);
    lls.push(9);
    lls.push(10);
    
    lls.display();
    cout<<"LLS TOP: "<<lls.top()<<endl;
    lls.pop();
    lls.display();
    return 0;
}
